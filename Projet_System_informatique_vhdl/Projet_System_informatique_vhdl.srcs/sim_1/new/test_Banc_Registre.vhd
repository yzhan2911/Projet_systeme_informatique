library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity test_Banc_Registre is
end test_Banc_Registre;

architecture Behavioral of test_Banc_Registre is
    -- Déclarations des signaux pour les entrées et sorties du module
    signal add_A, add_B, add_W : std_logic_vector(3 downto 0);
    signal W, RST, CLK : std_logic;
    signal DATA : std_logic_vector(7 downto 0);
    signal QA, QB : std_logic_vector(7 downto 0);

begin
    -- Processus de génération de l'horloge
    clk_process : process
    begin
        CLK <= '0';
        wait for 5 ns; -- Demi-période d'horloge
        CLK <= '1';
        wait for 5 ns; -- Demi-période d'horloge
    end process;

    -- Instanciation du module à tester
    uut : entity work.Banc_Registre
        port map (
            add_A => add_A,
            add_B => add_B,
            add_W => add_W,
            W => W,
            DATA => DATA,
            RST => RST,
            CLK => CLK,
            QA => QA,
            QB => QB
        );

    -- Processus de génération des stimuli
    stimulus_process : process
    begin
        -- Initialisation
        RST <= '1';
        W <= '0';
        DATA <= (others => '0');
        add_A <= "0000"; -- Adresse A
        add_B <= "0001"; -- Adresse B
        add_W <= "0010"; -- Adresse W
        wait for 10 ns;

        -- Désactivation de la réinitialisation
        RST <= '0';
        wait for 10 ns;
        
        -- Cycle de lecture-écriture
        -- Écriture à l'adresse W
        W <= '1';
        DATA <= x"FF"; -- Données à écrire
        wait for 10 ns;

        -- Lecture à l'adresse A
        W <= '0';
        add_A <= "0010"; -- Changement de l'adresse de lecture pour QA
        wait for 10 ns;

        -- Lecture à l'adresse B
        add_B <= "0010"; -- Changement de l'adresse de lecture pour QB
        wait for 10 ns;
         
        -- Test D=>Q
        W <= '1';
        add_A <= "0101";
        add_W <= "0101";
        wait for 10 ns;
        
        -- Ajoutez d'autres cycles de test si nécessaire

        wait;
    end process stimulus_process;

end Behavioral;
