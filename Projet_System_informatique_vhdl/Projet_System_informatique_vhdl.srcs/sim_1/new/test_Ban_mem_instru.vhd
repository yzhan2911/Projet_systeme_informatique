----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 09:40:28 AM
-- Design Name: 
-- Module Name: test_Ban_mem_instru - Behavioral
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

entity test_Ban_mem_instru is
end test_Ban_mem_instru;

architecture Behavioral of test_Ban_mem_instru is
    signal add : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal CLK : STD_LOGIC := '0';
    signal dataOUT : STD_LOGIC_VECTOR(31 downto 0);

   begin
        uut:  entity work.Banc_mem_instru
            port map (
                add => add,
                CLK => CLK,
                dataOUT => dataOUT
            );

    
    clk_process : process
    begin
        CLK <= '0';
        wait for 10 ns;
        CLK <= '1';
        wait for 10 ns;
    end process;

    -- Test process
    test_proc : process
    begin
         
       for i in 0 to 255 loop
            add <= std_logic_vector(to_unsigned(i, 8));

            wait for 20 ns;
           
       end loop;

     
        wait;
    end process;

end Behavioral;
