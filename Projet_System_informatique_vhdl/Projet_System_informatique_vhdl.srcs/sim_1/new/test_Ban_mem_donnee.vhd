----------------------------------------------------------------------------------
-- Testbench for Banc_mem_donne
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity test_Ban_mem_donnee is
end test_Ban_mem_donnee;

architecture Behavioral of test_Ban_mem_donnee is

    signal add : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal dataIN : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal RW : STD_LOGIC := '0';
    signal RST : STD_LOGIC := '0';
    signal CLK : STD_LOGIC := '0';
    signal dataOUT : STD_LOGIC_VECTOR(7 downto 0);

    
    begin
        uut:  entity work.Banc_mem_donne
            port map (
                add => add,
                dataIN => dataIN,
                RW => RW,
                RST => RST,
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
        -- Reset
        RST <= '0';
       

        -- Write to memory
        add <= "00000001";
        dataIN <= x"AA";
        RW <= '0'; 
        wait for 20 ns;

        -- reading mode
        RW <= '1';  
        wait for 20 ns;
        

        -- Check the output
        assert dataOUT = x"AA"
        report "read data incorrect!" severity error;

        wait for 20 ns;
        RST <= '1';
        assert dataOUT = x"00"
        report "reset incorrect!" severity error;
        
        wait;
    end process;

end Behavioral;
