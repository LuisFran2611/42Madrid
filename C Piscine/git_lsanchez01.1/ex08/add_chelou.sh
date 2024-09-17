#FT_NBR1='\"\"!\"\"!\"\"!\"\"!\"\"!\"\"'
#FT_NBR2='dcrcmcmooododmrrrmorcmcrmomo'
#FT_B1 ='\”?!
#FT_B2 =mrdoc 
#FT_B3 =gtaio luSnemf

Num1=$(echo $FT_NBR1 |tr "'\"?!" '0234'|tr '\\' '1');
Num2=$(echo $FT_NBR2 |tr 'mrdoc' '01234');
Num1_D=$(echo "ibase=5;$Num1" | bc);
Num2_D=$(echo "ibase=5;$Num2" | bc);
Sum_D=$(echo "$Num1_D + $Num2_D" | bc);
Sum=$(echo "obase=13;$Sum_D" | bc);
echo $Sum|tr '0123456789ABC' "gtaio luSnemf"
#printf "N1: $Num1 \n";
#printf "N2: $Num2 \n";
#printf "N1decimal: $Num1_D \n";
#printf "N2decimal: $Num2_D \n";
#printf "Suma: $Sum_D \n";
#printf "Salida: $Sum \n";
