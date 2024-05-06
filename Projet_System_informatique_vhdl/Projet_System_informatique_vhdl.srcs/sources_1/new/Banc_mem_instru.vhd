----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/03/2024 11:44:12 AM
-- Design Name: 
-- Module Name: Banc_mem_instru - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values


-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Banc_mem_instru is
    Port ( add : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           dataOUT : out STD_LOGIC_VECTOR (31 downto 0));
end Banc_mem_instru;

architecture Behavioral of Banc_mem_instru is
    type ROM_Array is array (0 to 255) of STD_LOGIC_VECTOR(31 downto 0);
     signal ROM : ROM_Array := ((x"00000001"),(x"00000002"),(x"00000003"),others=>(x"00000004"));
  

begin
 process
    begin
 
        wait until clk'event and clk = '1';    
        dataOUT <= ROM(to_integer(unsigned(add))); 
       
    end process;
    
end Behavioral;

