----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 10:35:33 AM
-- Design Name: 
-- Module Name: component_EX_Mem - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity component_EX_Mem is
 Port ( 
 InA, InB,InOp : in std_logic_vector (7 downto 0);
 OutA, OutB, OutOp : out std_logic_vector (7 downto 0);
 Clk : in std_logic);
end component_EX_Mem;

architecture Behavioral of component_EX_Mem is

begin
    process 
    begin 
        wait until Clk'event and Clk='1';
        OutA<=InA;
        OutB<=InB;
        OutOp<=InOp;
    end process;
end Behavioral;