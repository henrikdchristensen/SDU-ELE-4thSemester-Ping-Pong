--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : Schem.vhf
-- /___/   /\     Timestamp : 05/26/2015 14:46:42
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -sympath "C:/Users/Christian/Dropbox/Projekt (PRO) 4. semester/Projekt-CD/FPGA kode/ipcore_dir" -intstyle ise -family spartan3e -flat -suppress -vhdl "C:/Users/Christian/Dropbox/Projekt (PRO) 4. semester/Projekt-CD/FPGA kode/Schem.vhf" -w "C:/Users/Christian/Dropbox/Projekt (PRO) 4. semester/Projekt-CD/FPGA kode/Schem.sch"
--Design Name: Schem
--Device: spartan3e
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity Schem is
   port ( clk50_in  : in    std_logic; 
          MOSI      : in    std_logic; 
          SClk      : in    std_logic; 
          SS        : in    std_logic; 
          SW        : in    std_logic_vector (7 downto 0); 
          tgl_btn   : in    std_logic_vector (1 downto 0); 
          abcdefg   : out   std_logic_vector (7 downto 0); 
          AN        : out   std_logic_vector (3 downto 0); 
          blue_out  : out   std_logic_vector (1 downto 0); 
          Data      : out   std_logic_vector (0 downto 0); 
          green_out : out   std_logic_vector (2 downto 0); 
          hs_out    : out   std_logic; 
          LED       : out   std_logic_vector (18 downto 0); 
          red_out   : out   std_logic_vector (2 downto 0); 
          vs_out    : out   std_logic);
end Schem;

architecture BEHAVIORAL of Schem is
   signal XLXN_11    : std_logic_vector (18 downto 0);
   signal XLXN_13    : std_logic;
   signal XLXN_17    : std_logic_vector (0 downto 0);
   signal XLXN_27    : std_logic_vector (0 downto 0);
   signal LED_DUMMY  : std_logic_vector (18 downto 0);
   signal Data_DUMMY : std_logic_vector (0 downto 0);
   component SPI
      port ( Clk     : in    std_logic; 
             SClk    : in    std_logic; 
             SS      : in    std_logic; 
             MOSI    : in    std_logic; 
             WE      : out   std_logic; 
             Databus : out   std_logic; 
             Adrbus  : out   std_logic_vector (18 downto 0));
   end component;
   
   component Memory
      port ( addra : in    std_logic_vector (18 downto 0); 
             dina  : in    std_logic_vector (0 downto 0); 
             wea   : in    std_logic_vector (0 downto 0); 
             clka  : in    std_logic; 
             addrb : in    std_logic_vector (18 downto 0); 
             clkb  : in    std_logic; 
             doutb : out   std_logic_vector (0 downto 0));
   end component;
   
   component VGA
      port ( clk50_in  : in    std_logic; 
             color     : in    std_logic; 
             SW        : in    std_logic_vector (7 downto 0); 
             tgl_btn   : in    std_logic_vector (1 downto 0); 
             hs_out    : out   std_logic; 
             vs_out    : out   std_logic; 
             clk_synch : out   std_logic; 
             red_out   : out   std_logic_vector (2 downto 0); 
             green_out : out   std_logic_vector (2 downto 0); 
             blue_out  : out   std_logic_vector (1 downto 0); 
             adr       : out   std_logic_vector (18 downto 0); 
             AN        : out   std_logic_vector (3 downto 0); 
             abcdefg   : out   std_logic_vector (7 downto 0));
   end component;
   
begin
   Data(0 downto 0) <= Data_DUMMY(0 downto 0);
   LED(18 downto 0) <= LED_DUMMY(18 downto 0);
   XLXI_2 : SPI
      port map (Clk=>clk50_in,
                MOSI=>MOSI,
                SClk=>SClk,
                SS=>SS,
                Adrbus(18 downto 0)=>LED_DUMMY(18 downto 0),
                Databus=>Data_DUMMY(0),
                WE=>XLXN_17(0));
   
   XLXI_3 : Memory
      port map (addra(18 downto 0)=>LED_DUMMY(18 downto 0),
                addrb(18 downto 0)=>XLXN_11(18 downto 0),
                clka=>clk50_in,
                clkb=>XLXN_13,
                dina(0)=>Data_DUMMY(0),
                wea(0)=>XLXN_17(0),
                doutb(0)=>XLXN_27(0));
   
   XLXI_4 : VGA
      port map (clk50_in=>clk50_in,
                color=>XLXN_27(0),
                SW(7 downto 0)=>SW(7 downto 0),
                tgl_btn(1 downto 0)=>tgl_btn(1 downto 0),
                abcdefg(7 downto 0)=>abcdefg(7 downto 0),
                adr(18 downto 0)=>XLXN_11(18 downto 0),
                AN(3 downto 0)=>AN(3 downto 0),
                blue_out(1 downto 0)=>blue_out(1 downto 0),
                clk_synch=>XLXN_13,
                green_out(2 downto 0)=>green_out(2 downto 0),
                hs_out=>hs_out,
                red_out(2 downto 0)=>red_out(2 downto 0),
                vs_out=>vs_out);
   
end BEHAVIORAL;


