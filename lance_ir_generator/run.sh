#! /bin/bash

for i in /home/anushkini/Desktop/PD/plagtool/Test_lance/*.c ;
do
	compile $i
	if [[ $? -ne 0 ]]
	then
		break
	fi
	./myapp ${i%%.*}".ir.c"
done
