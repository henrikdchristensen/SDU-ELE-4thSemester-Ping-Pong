library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity VGA is
  port(
-- inputs:  
			clk50_in: in std_logic;
			color:	 in std_logic;
			SW:		 in std_logic_vector (7 downto 0);
			tgl_btn:	 in std_logic_vector ( 1 downto 0);
-- outputs:
			red_out:	 out std_logic_vector (2 downto 0);
			green_out:out std_logic_vector (2 downto 0);
			blue_out: out std_logic_vector (1 downto 0);
			hs_out:	 out std_logic;
			vs_out:	 out std_logic;
			adr:		 out std_logic_vector ( 18 downto 0);
			AN:		 out std_logic_vector ( 3 downto 0) := "0111";
			abcdefg:	 out std_logic_vector ( 7 downto 0);
			clk_synch:out std_logic
		 );
end VGA;

architecture Behavioral of VGA is

signal clk25              : std_logic;
signal clk100hz	        : std_logic_vector ( 9 downto 0);
signal wait1				  : std_logic;
signal Adrcount			  : std_logic_vector (18 downto 0);
signal horizontal_counter : std_logic_vector (9 downto 0);
signal vertical_counter   : std_logic_vector (9 downto 0);
signal red_color			  : std_logic_vector (2 downto 0) := "101";signal blue_color			  : std_logic_vector (1 downto 0) := "11";
signal green_color		  : std_logic_vector (2 downto 0) := "011";
signal red_color_off		  : std_logic_vector (2 downto 0) := "000";signal blue_color_off	  : std_logic_vector (1 downto 0) := "00";
signal green_color_off	  : std_logic_vector (2 downto 0) := "000";
signal an_select			  : std_logic_vector (3 downto 0) := "0000";


begin

-- Generates a 25Mhz clock 
process (clk50_in)
begin
  if clk50_in'event and clk50_in='1' then
    if (clk25 = '0') then
      clk25 <= '1';
		clk100hz <= clk100hz + 1; -- Generates the clock used when displaying PONg on the display	
    else
      clk25 <= '0';
    end if;
  end if;
end process;

process (clk25)
begin
	--Writes screen data, when front- and back porch and the pulse width has been passed.
  if clk25'event and clk25 = '1' then
    if (horizontal_counter >= "0010010000" ) -- 144 -- Front porch and pulse width has been passed
    and (horizontal_counter < "1100010000" ) -- 784 -- backporch starts
    and (vertical_counter >= "0000100111" ) -- 39
    and (vertical_counter < "1000000111" ) -- 519
    then

--	 horizontal <= horizontal_counter-"10010000"; 
	 adr <= Adrcount;	--Sends read address to memory
	 Adrcount <= Adrcount + 1; --Increments address
			
		-- Writes 1 or 0 on pixel, depending on value returned from memory	
		-- color is databit from memory
		if color = '1' then
			red_out <= red_color;
			green_out <= green_color;
			blue_out <= blue_color;
	  
		else
			red_out <= red_color_off;
			green_out <= green_color_off;
			blue_out <= blue_color_off;
		end if;

	 -- Writes nothing in back and front porch.
	 else
	 	red_out <= "000";
		green_out <= "000";
		blue_out <= "00";		
	 end if;

	 -- Sets horizontal sync to low while in front porch.
	 -- Horizontal sync is high otherwise
    if (horizontal_counter > "0000000000" )
      and (horizontal_counter < "0001100001" ) -- 96+1
    then
      hs_out <= '0';
    else
      hs_out <= '1'; 
    end if;
	 
	 -- Sets vertical sync to low during the first pulse width.
	 -- Vertical sync is high otherwise
    if (vertical_counter > "0000000000" )
      and (vertical_counter < "0000000011" ) -- 2+1
    then
      vs_out <= '0';
    else
      vs_out <= '1';
    end if;
	
    horizontal_counter <= horizontal_counter+"0000000001"; -- Increments horizontal counter
	
	-- If horizontal has reached the edge, reset counter
    if (horizontal_counter="1100100000") then -- 800: Front porch + back porch + display time + pulse width
      vertical_counter <= vertical_counter+"0000000001"; -- Next vertical line
      horizontal_counter <= "0000000000";
    end if;
	
	-- If vertical has been to the bottom, reset counter
    if (vertical_counter="1000001001") then -- 521: Front porch + back porch + display time + pulse width
      vertical_counter <= "0000000000";
		Adrcount <= "0000000000000000000"; -- Resets the addresscounter as the screen will start over
    end if;
  end if;
end process;

process (clk50_in)
begin
	-- If the first togglebutton has been pushed, 
	-- the bats and border color will change to the color the swithes indicates
	if (tgl_btn = "01") then
		red_color(0) <= SW(0);
		red_color(1) <= SW(1);
		red_color(2) <= SW(2);
		green_color(0) <= SW(3);
		green_color(1) <= SW(4);
		green_color(2) <= SW(5);
		blue_color(0) <= SW(6);
		blue_color(1) <= SW(7);						 
	end if;

	-- If the second togglebutton has been pushed, 
	-- the background color will change to the color the swithes indicates
	if (tgl_btn = "10") then
		red_color_off(0) <= SW(0);
		red_color_off(1) <= SW(1);
		red_color_off(2) <= SW(2);
		green_color_off(0) <= SW(3);
		green_color_off(1) <= SW(4);
		green_color_off(2) <= SW(5);
		blue_color_off(0) <= SW(6);
		blue_color_off(1) <= SW(7);
	end if;

end process;

process (clk25)
begin
if rising_edge (clk25) then
	--Writes PONg in the display
	case clk100hz(9 downto 8) is
		when "00" =>
			abcdefg <= "10001100";
			AN <= "0111";
		when "01" =>
			abcdefg <= "11000000";
			AN <= "1011";
		when "10" =>
			abcdefg <= "11001000";
			AN <= "1101";
		when "11" =>
			abcdefg <= "10010000";
			AN <= "1110";
		when others =>
			an_select <= "0000";
	end case;
end if;
end process;


	-- Create outputs. 
	clk_synch <= clk25;
	
end Behavioral;