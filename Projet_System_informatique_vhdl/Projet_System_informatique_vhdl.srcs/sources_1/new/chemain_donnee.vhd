----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 10:33:38 AM
-- Design Name: 
-- Module Name: chemain_donnee - Behavioral
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values


-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity chemain_donnee is
  Port ( 
  RST : in std_logic:='0';
  CLK : in std_logic:='0';
  valeur: out STD_LOGIC_VECTOR (7 downto 0);
  add : out STD_LOGIC_VECTOR (3 downto 0)

  );
end chemain_donnee;

architecture Behavioral of chemain_donnee is
component compteur8bit 
port(
  CK,SENS,RST,LOAD,EN : in std_logic;
  Din : in std_logic_vector(7 downto 0);
  Dout : out std_logic_vector(7 downto 0)
);
end component;
signal compteur_out :  std_logic_vector(7 downto 0):=(others=>'0');
component Banc_mem_instru 
   Port ( add : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           dataOUT : out STD_LOGIC_VECTOR (31 downto 0));
end component;
signal mem_instru_out :  std_logic_vector(31 downto 0):=(others=>'1');

component  component_LI_DI 
 Port ( 
 InA, InB, InC,InOp : in std_logic_vector (7 downto 0);
 OutA, OutB, OutC,OutOp : out std_logic_vector (7 downto 0);
 Clk : in std_logic);
 end component;
 
 component component_DI_EX 
 Port ( 
 InA, InB, InC,InOp : in std_logic_vector (7 downto 0);
 OutA, OutB, OutC,OutOp : out std_logic_vector (7 downto 0);
 Clk : in std_logic);
end component;

component component_EX_Mem 
 Port ( 
 InA, InB,InOp : in std_logic_vector (7 downto 0);
 OutA, OutB, OutOp : out std_logic_vector (7 downto 0);
 Clk : in std_logic);
end component;

component component_Mem_RE 
 Port ( 
 InA, InB,InOp : in std_logic_vector (7 downto 0);
 OutA, OutB, OutOp : out std_logic_vector (7 downto 0);
 Clk : in std_logic);
end component;

component Banc_Registre
    Port ( add_A : in STD_LOGIC_VECTOR (3 downto 0);
           add_B : in STD_LOGIC_VECTOR (3 downto 0);
           add_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end component;


component ALU 
Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0);  
           S : out STD_LOGIC_VECTOR (7 downto 0);
           N : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           C : out STD_LOGIC
           );
end component;
component Banc_mem_donne 
    Port ( add : in STD_LOGIC_VECTOR (7 downto 0);
           dataIN : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           dataOUT : out STD_LOGIC_VECTOR (7 downto 0));
end component;
    
signal JMF :std_logic :='0';
signal enable:std_logic;
signal addJMF: STD_LOGIC_VECTOR (7 downto 0) := (others=>'0');

signal LI_DI_A:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal LI_DI_B:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal LI_DI_C:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal LI_DI_Op:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');



signal DI_EX_A:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal DI_EX_B:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal DI_EX_C:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal DI_EX_Op:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal LI_DI_final_B:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');

signal EX_MEM_A:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal EX_MEM_B:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal EX_MEM_Op:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal DI_EX_final_B:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');



signal Mem_RE_A:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal Mem_RE_B:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal Mem_RE_Op:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal EX_Mem_final_B :STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');

-- banc registre
signal banc_registre_w:std_logic :='0';
signal banc_registre_QA:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');
signal banc_registre_QB:STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');

-- UAL
signal Ctrl_Alu :  STD_LOGIC_VECTOR (2 downto 0) := (others=>'1');  
signal ALU_S :  STD_LOGIC_VECTOR (7 downto 0) := (others=>'1');  
signal ALU_N,ALU_O,ALU_Z,ALU_C : std_logic; 


-- Memoir des données
signal LC_RW :STD_LOGIC ;
signal dataOUT_mem_data :STD_LOGIC_VECTOR (7 downto 0):= (others=>'1');
signal EX_Mem_avant_addr:STD_LOGIC_VECTOR (7 downto 0):= (others=>'1');

begin
IP : compteur8bit port map(
     CK=> CLK,
     SENS=>'1',
     RST=>RST,
     LOAD=>JMF,
     EN=> enable,
  Din => addJMF,
  Dout =>compteur_out);

mem_instru:Banc_mem_instru port map(
    add=>compteur_out, 
     CLK=>CLK , 
      dataOUT=> mem_instru_out  
);

LI_DI:component_LI_DI port map(
  InA =>mem_instru_out(23 downto 16),
  InB=>mem_instru_out(15 downto 8),
  InC=>mem_instru_out(7 downto 0),
  InOp=>mem_instru_out(31 downto 24),
  OutA=>LI_DI_A,
  OutB=>LI_DI_B,
  OutC=>LI_DI_C,
  OutOp=>LI_DI_Op,
  Clk =>CLK);

registre:  Banc_Registre Port map(
          add_W =>Mem_RE_A(3 downto 0),
          W=>banc_registre_w ,
          DATA=>Mem_RE_B,
          RST=>RST,
          CLK=>CLK,
          add_A=>LI_DI_B(3 downto 0),
          add_B=>LI_DI_C(3 downto 0),
          QA=>banc_registre_QA,
          QB=>banc_registre_QB);

DI_EX:component_DI_EX port map( 
  InA=>LI_DI_A,
  InB=>LI_DI_final_B,
  InC=>banc_registre_QB,
  InOp=>LI_DI_Op, 
  OutA=>DI_EX_A,
  OutB=>DI_EX_B,
  OutC=>DI_EX_C,
  OutOp=>DI_EX_Op, 
 Clk=>CLK);

UAL :  ALU port map ( 
           A=>DI_EX_B, 
           B=>DI_EX_C,
           Ctrl_Alu=>Ctrl_Alu,  
           S =>ALU_S,
           N => ALU_N,
           O => ALU_O,
           Z => ALU_Z,
           C => ALU_C);

EX_Mem:component_EX_Mem port map( 
  InA=>DI_EX_A,
  InB=>DI_EX_final_B,
  InOp=>DI_EX_Op, 
  OutA=>EX_Mem_A,
  OutB=>EX_Mem_B,
  OutOp=>EX_Mem_Op, 
 Clk=>CLK);
 
Mem_data:  Banc_mem_donne port map (
           add=>EX_Mem_avant_addr,
           dataIN=>EX_Mem_B ,
           RW =>LC_RW,
           RST =>RST,
           CLK =>CLK,
           dataOUT=>dataOUT_mem_data);

Mem_RE:component_Mem_RE port map( 
  InA=>EX_Mem_A,
  InB=>EX_Mem_final_B,
  InOp=>EX_Mem_Op, 
  OutA=>Mem_RE_A,
  OutB=>Mem_RE_B,
  OutOp=>Mem_RE_Op, 
  Clk=>CLK);








-- ADD      0x01
-- MUL      0x02
-- SOU      0x03
-- DIV      0x04
-- COP      0x05
-- AFC      0x06
-- LOAD     0x07
-- STORE    0x08

-- LC pour  Mem_RE
banc_registre_w <= '0' when Mem_RE_Op = x"08" or Mem_Re_op = x"ff"  --- store ou null
                   else  '1';

-- LC pour UAL
Ctrl_Alu <="000" when DI_EX_Op=x"05" or DI_EX_Op=x"06" or DI_EX_Op=x"07" or DI_EX_Op=x"08"  -- cop afc load store
        else DI_EX_Op(2 downto 0); -- + -* /
    
-- LC pour memoir des donnees
LC_RW <= '0' when EX_Mem_Op =x"08" 
    else '1';

-- mux apres banc de registre
LI_DI_final_B<= LI_DI_B when LI_DI_Op = x"06" or  LI_DI_Op = x"07"  --- AFC ou Load
               else banc_registre_QA;

-- mux apres UAL 
DI_EX_final_B <= DI_EX_B when  DI_EX_Op = x"05" or DI_EX_Op = x"06" or DI_EX_Op = x"07" or DI_EX_Op = x"08"  -- cop afc load store
               else ALU_S;

-- mux apres memoir des donnees
EX_Mem_final_B <= dataOUT_mem_data when EX_Mem_Op =x"07" or EX_Mem_Op =x"08" --  load store
                else EX_Mem_B;

-- mux avant memoir des donnees
EX_Mem_avant_addr <= EX_Mem_A when EX_Mem_Op =x"07" or EX_Mem_Op =x"08" --  load store
                   else EX_Mem_B;
 
end Behavioral;
