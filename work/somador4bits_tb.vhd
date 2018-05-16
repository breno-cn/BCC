library ieee;
use ieee.std_logic_1164.all;

entity somador4bits_tb is
end somador4bits_tb;

architecture TB of somador4bits_tb is
  

component somador4bits is
  port(
    opa    : IN std_logic_vector(3 downto 0);
    opb    : IN std_logic_vector(3 downto 0);
    ops    : OUT std_logic_vector(3 downto 0);
    opcout : OUT std_logic
    );
  end component;
  
  signal A, B  :         std_logic_vector(3 downto 0);
  signal carry :         std_logic;
  signal S     :         std_logic_vector(3 downto 0);
  
  begin
    UUT_s4bits: somador4bits port map (A, B, S, carry);
      
    process begin 
      
      --case 1
      A <= "0000";
      B <= "0000";
      Wait for 10 ns;
      assert (s="0000") report "Error!" severity error;
      assert (carry='0') report "Carry Error!" severity error;
      
      --case 2
      A <= "1111";
      B <= "0001";
      wait for 10 ns;
      assert (s="0000") report "Sum Error!" severity error;
      assert (carry='1') report "Carry Error!" severity error;
      wait;
      
  end process;
  
end TB;
