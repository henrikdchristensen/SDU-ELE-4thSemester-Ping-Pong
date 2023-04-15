library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity SPI is
	port(	
-- inputs:
			Clk: 		in 	STD_LOGIC;
			SClk: 	in 	STD_LOGIC;
			SS: 		in		STD_LOGIC;
			MOSI: 	in		STD_LOGIC;
-- outputs:
			WE:		out	STD_LOGIC := '0';
			Databus:	out	STD_LOGIC;
			Adrbus:	out	STD_LOGIC_VECTOR(18 downto 0)
			);
end SPI;

architecture Behavioral of SPI is

-- states for state machine
type States is (
							wait_for_SS_first_low,
							wait_for_SS_second_low,
							receive_first_data,
							receive_second_data,
							send_data);
							
-- start state selection							
	signal State: States := wait_for_SS_first_low;
	
-- variables
	signal	SScnt:		std_logic_vector(1 downto 0)	:= (others => '0');
	signal	SClkcnt:		integer	:= 0;
	signal	SClkcnt_old:integer := 0;
	
	signal xSS:				STD_LOGIC_VECTOR(1 downto 0) := "00";
	signal xSClk:			STD_LOGIC_VECTOR(1 downto 0) := "00";
	
	signal inbufA: 		STD_LOGIC_VECTOR (9 downto 0);  -- register to the first 10 bits
	signal inbufB: 		STD_LOGIC_VECTOR (9 downto 0); -- register to the last 10 bits
	signal outbuf:			STD_LOGIC_VECTOR (19 downto 0) := (others => '0'); -- register for 20 bits (data and address)

begin
-- Process to detect the rising and falling edge for SS and SClk 	
edgedetector: process(Clk)
	begin
		if falling_edge(Clk) then
			xSClk	<=	xSClk(0)	&	SClk; --  saves the value for SClk into xSClk
			xSS	<=	xSS(0)	&	SS; -- saves the value for SS into xSS
		end if;
		if rising_edge(Clk) then
			if xSS = "10" then	-- if falling edge on SS
				SScnt <= SScnt + 1;
				SClkcnt <= 0;
			end if;
			if	xSS = "01" then	-- if rising edge on SS
				if SScnt > "01" then -- if SScnt is greater then 1, reset SScnt
					SScnt <= "00";
				end if;
			end if;
			if xSClk = "01" then -- rising edge on  SClk
				SClkcnt <= SClkcnt + 1;
			end if;
		end if;
	end process;
	
	
-- Main program (state machine)
State_Machine: process(CLK)
	begin
		if rising_edge(CLK) then
			case State is

				-- checking SScnt. If first rising edge on SScnt, go to next state, otherwise wait here
				when Wait_for_SS_first_low =>
					WE <= '0';
					if	SScnt = "01" then
						State	<=	receive_first_data;
					end if;

						
				-- save the first 10 bits in inbufA
				when receive_first_data =>		
					if SClkcnt 	=	SClkcnt_old + 1 then -- if rising edge on SClkcnt
						SClkcnt_old	<=	SClkcnt;
						
						if SScnt = "01" then -- if the first 10 bits
							inbufA(9-(SClkcnt-1)) <= MOSI; -- saves the first bit from the ARM, into the last place in inbufA				
							if SClkcnt = 10 then -- receive first 10 bits, go to next state (wait_for_SS_second_low)
								State <= wait_for_SS_second_low;
								SClkcnt_old <= 0;
							end if;
						end if;	
					end if;


				-- checking SScnt. If second rising edge on SScnt, go to next state, otherwise wait here
				when Wait_for_SS_second_low =>
					if SScnt = "10" then
						State <= receive_second_data;
					end if;
					

				-- save the last 10 bits in inbufB
				when receive_second_data =>
					if SClkcnt 	=	SClkcnt_old + 1 then -- if rising edge on SClkcnt
						SClkcnt_old	<=	SClkcnt;
						
						if SScnt = "10" then -- if the last 10 bits
							inbufB(9-(SClkcnt-1)) <= MOSI; -- saves the first bit from the ARM, into the last place in inbufB
							if SClkcnt = 10 then -- receive last 10 bits, go to next state (send_data)
								State <= send_data;
								SClkcnt_old <= 0;
							end if;
						end if;
					end if;

				
				-- send 20 bit from outbuf
				when send_data =>
					outbuf <= inbufA & inbufB;
					Adrbus 	<= outbuf(19 downto 1); -- put the last 19 bits to Adrbus
					Databus	<=	outbuf(0); -- put out the first bit to Databus
					WE <= '1'; -- WriteEnable on
					State <= wait_for_SS_first_low; -- go to next state and wait for new data to be received 
					
				when others =>
					State <= wait_for_SS_first_low;
					
			end case;
		end if;
	end process;
end Behavioral;

