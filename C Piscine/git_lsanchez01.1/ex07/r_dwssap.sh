
#FT_LINE1=1
#FT_LINE2=10
cat /etc/passwd | sed -n 'n;p' | cut -d ':' -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p"|sed ':a;N;$!ba;s/\n/, /g'|sed 's/$/./'|tr -d '\n'
