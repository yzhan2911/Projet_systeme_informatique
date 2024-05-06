----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/03/2024 10:47:21 AM
-- Design Name: 
-- Module Name: test_ALU - Behavioral
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

entity test_ALU is
end test_ALU;

architecture Behavioral of test_ALU is
 component ALU
    Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0);
           N : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           C : out STD_LOGIC);
    end component ;
    signal A : STD_LOGIC_VECTOR (7 downto 0);
    signal B : STD_LOGIC_VECTOR (7 downto 0);
    signal Ctrl_Alu : STD_LOGIC_VECTOR (2 downto 0);
    signal S : STD_LOGIC_VECTOR (7 downto 0);
    signal N, O, Z, C : STD_LOGIC;
begin
    uut: entity work.ALU 
    port map(
    A => A,
    B => B,
    Ctrl_Alu => Ctrl_Alu,
    S => S,
    N => N,
    O => O,
    Z => Z,
    C => C
    );
 -- Test process
    process
    begin
    -- Test 1: Addition
    A <= "00000001"; -- 1
    B <= "00000001"; -- 1
    Ctrl_Alu <= "001"; -- ADD
    wait for 10 ns;
    
    assert S = "00000010" and C = '0' and O = '0' and N = '0' and Z = '0'
    report "Test Addition failed" severity error;
    

    
    -- Test 2: Subtraction
    A <= "00000010"; -- 2
    B <= "00000001"; -- 1
    Ctrl_Alu <= "010"; -- SUB
    wait for 10 ns;
    
    assert S = "00000001" and C = '0' and O = '0' and N = '0' and Z = '0'
    report "Test Subtraction failed" severity error;
    
    -- Test 3: Multiplication
    A <= "00000010"; -- 2
    B <= "00000011"; -- 3
    Ctrl_Alu <= "011"; -- MUL
    wait for 10 ns;
    
    assert S = "00000110" and C = '0' and O = '0' and N = '0' and Z = '0'
    report "Test Multiplication failed" severity error;
       
    -- Test 4: Division
    A <= "00000110"; -- 6
    B <= "00000011"; -- 3
    Ctrl_Alu <= "100"; -- DIV
    wait for 10 ns;
    
    assert S = "00000010" and C = '0' and O = '0' and N = '0' and Z = '0'
    report "Test Division failed" severity error;
    
    
     -----test carry 
    A <= "11111111"; 
    B <= "11111111"; 
    Ctrl_Alu <= "001"; 
    wait for 10 ns;

    assert C = '1' and O = '0' and N = '0' and Z = '0'
    report "Test carry failed" severity error;
    
    -----test overflow 
    A <= "11111111"; 
    B <= "11111111"; 
    Ctrl_Alu <= "011"; 
    wait for 10 ns;
 
    assert C = '0' and O = '1' and N = '0' and Z = '0'
    report "Test overflow failed" severity error;
    
    -----test Zeros 
    A <= "11111111"; 
    B <= "00000000"; 
    Ctrl_Alu <= "100"; 
    wait for 10 ns;
 
    assert C = '0' and O = '0' and N = '0' and Z = '1'
    report "Test Zeros failed" severity error;
    
    -----test negative 
    A <= "00000001"; 
    B <= "00000011"; 
    Ctrl_Alu <= "010"; 
    wait for 10 ns;
 
    assert C = '0' and O = '0' and N = '1' and Z = '0'
    report "Test negative failed" severity error;
    
    wait;
    end process;
end Behavioral;
