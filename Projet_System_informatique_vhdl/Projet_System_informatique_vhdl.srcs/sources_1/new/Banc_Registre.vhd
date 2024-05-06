----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/03/2024 11:40:11 AM
-- Design Name: 
-- Module Name: Banc_Registre - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Banc_Registre is
    Port ( add_A : in STD_LOGIC_VECTOR (3 downto 0);
           add_B : in STD_LOGIC_VECTOR (3 downto 0);
           add_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end Banc_Registre;

architecture Behavioral of Banc_Registre is
    type ArrayType is array(0 to 15) of std_logic_vector(7 downto 0); 
    signal tab_registre:ArrayType :=(others=>x"00");
begin
     process 
     begin
        wait until CLK'event and CLK = '1';
        
        if RST = '1' then  
           tab_registre<=(others=>x"00");
        elsif W = '1' then 
           tab_registre(to_integer(unsigned(add_W)))<=DATA; 
        end if;
        if W='1'and add_A=add_W then
            QA<=DATA;
        elsif W='1' and add_B=add_W then
            QB<=DATA;
        else
            QA<= tab_registre(TO_INTEGER(unsigned(add_A)));
            QB<= tab_registre(TO_INTEGER(unsigned(add_B)));
        end if;
        
     end process;
                
end Behavioral;
