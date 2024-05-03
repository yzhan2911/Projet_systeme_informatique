----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/03/2024 09:56:23 AM
-- Design Name: 
-- Module Name: ALU - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           Ctrl_Alu : in STD_LOGIC_VECTOR (1 downto 0);  
           S : out STD_LOGIC_VECTOR (7 downto 0);
           N : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           C : out STD_LOGIC
           );
end ALU;
-- Instruction code
    -- ADD    "01"    
    -- MUL    "02"
    -- SUB    "03"
    -- DIV    "04"
architecture Behavioral of ALUU is
    signal S_16bits,A_16bits,B_16bits : STD_LOGIC_VECTOR (15 downto 0); --16 bits
begin
    process(A,B,Ctrl_Alu)
        begin
        A_16bits<=x"00"& A;B_16bits<=x"00"&B; --transferer en 16 bits
        case Control is 
           when "01"=> ---addtion
           S_16bits <= A_16bits + B_16bits;
           when "02"=> ---soustraction
           S_16bits <= A_16bits - B_16bits;
           when "03"=> --- multiplication
           S_16bits <= A*B;
           when "04"=> --division
           if (B /= 0) then S_16bits <= ( std_logic_vector(to_unsigned(to_integer(unsigned(A_16bits)) / to_integer(unsigned(B_16bits)),16))); 
           else S_16bits <= x"0000"; 
           end if;
           end case;
        end process;
            C <= '1' when S_16bits(15 downto 8) /= x"00" and Ctrl_Alu = "01" else '0';--- Carry pour addition
            O <= '1' when S_16bits(15 downto 8) /= x"00"  else '0'; --- overflow
            N <= '1' when S_16bits(15)=='1' else '0'; ---negative
            Z <= '1' when S_16bits(15 downto 0) ==x"00" else '0'; --- zeros
            S <= S_16bits(7 downto 0 ) ; 

end Behavioral;
