----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/03/2024 11:44:12 AM
-- Design Name: 
-- Module Name: Banc_mem_donne - Behavioral
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

entity Banc_mem_donne is
    Port ( add : in STD_LOGIC_VECTOR (7 downto 0);
           dataIN : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           dataOUT : out STD_LOGIC_VECTOR (7 downto 0));
end Banc_mem_donne;

architecture Behavioral of Banc_mem_donne is
    type Memoire_tab is array (0 to 4) of STD_LOGIC_VECTOR (7 downto 0);
    signal Memoire : Memoire_tab := (others => x"00");
begin
    process
    begin
        wait until clk'event and clk = '1';     --synchrones avec CLK.
        if RST = '1' then              -- Reset
            Memoire <= (others => x"00"); 
        elsif RW = '0' then          --écriture
                Memoire(to_integer(unsigned(add))) <= Data_in;
            end if;
        end if;
    end process;
    dataOUT <= Memoire(to_integer(unsigned(add))); --reading 

end Behavioral;
