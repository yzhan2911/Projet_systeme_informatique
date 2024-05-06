----------------------------------------------------------------------------------
-- Testbench for Banc_mem_donne
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Banc_mem_donne_tb is
-- Testbench has no ports
end Banc_mem_donne_tb;

architecture test of test_Banc_mem_donne is

    -- Component Declaration for the Unit Under Test (UUT)
    component Banc_mem_donne
        Port (
            add : in STD_LOGIC_VECTOR(7 downto 0);
            dataIN : in STD_LOGIC_VECTOR(7 downto 0);
            RW : in STD_LOGIC;
            RST : in STD_LOGIC;
            CLK : in STD_LOGIC;
            dataOUT : out STD_LOGIC_VECTOR(7 downto 0)
        );
    end component;

  
    signal add : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal dataIN : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal RW : STD_LOGIC := '0';
    signal RST : STD_LOGIC := '0';
    signal CLK : STD_LOGIC := '0';
    signal dataOUT : STD_LOGIC_VECTOR(7 downto 0);

    
    begin
        uut: component Banc_mem_donne
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
        RST <= '1';
        wait for 20 ns;
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

       
        wait;
    end process;

end test;
