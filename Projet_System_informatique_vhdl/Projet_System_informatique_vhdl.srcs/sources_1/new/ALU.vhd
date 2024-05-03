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
           Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0);  
           S : out STD_LOGIC_VECTOR (7 downto 0);
           N : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           C : out STD_LOGIC
           );
end ALU;
    -- ADD    "01"    
    -- MUL    "02"
    -- SUB    "03"
    -- DIV    "04"
architecture Behavioral of ALU is
    signal S_16bits,A_16bits,B_16bits : STD_LOGIC_VECTOR (15 downto 0):=(others =>'0'); --16 bits
begin

    process(A_16bits, B_16bits,A,B,Ctrl_Alu)
        begin
        A_16bits<=x"00"&A;
        B_16bits<=x"00"&B; --transferer en 16 bits
        N<= '0';
        O<='0';
        Z<='0';
        C<='0';
        case Ctrl_Alu is 
           when "001"=> ---addtion
               S_16bits <= A_16bits + B_16bits;
               if(A_16bits + B_16bits> 255) then C<='1';
               elsif (A_16bits + B_16bits=0) then Z<='1';
               end if;
           when "010"=> ---soustraction
               S_16bits <= A_16bits - B_16bits;
               if (B_16bits > A_16bits) then N<='1';
               elsif (B_16bits = A_16bits) then Z<='1';
               end if;
           when "011"=> --- multiplication
           S_16bits <= A*B;
           if (A*B>255)then O<='1';
           elsif(A*B=0) then Z<='1';
           end if;
           when "100"=> --division
           if (B /= 0) then S_16bits <= ( std_logic_vector(to_unsigned(to_integer(unsigned(A_16bits)) / to_integer(unsigned(B_16bits)),16))); 
           else S_16bits <= x"0000";Z<='1'; 
           end if;
           when others => -- Ajout du choix par défaut
            S_16bits <= (others => '0'); 
           end case;
        end process;
            
            S <= S_16bits(7 downto 0 ) ; 

end Behavioral;
