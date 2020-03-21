#!/bin/sh
python3 remove_include.py $1 #removes include statements in the C files

cd source/$1/

#Convert to IR using Lance - generates ir.c files
for filename in ./*.c; do
	compile "$filename"
done

#Dead code elimination
for filename in ./*.ir.c; do
        dce "$filename"
done

#Symbol table cleanup
for filename in ./*.ir.c; do
        stcleanup "$filename"
done

cd ..
cd ..

#Running MOSS
mkdir submission/$1
mkdir submission/$1/moss/
python3 m.py $1

mkdir source/$1/jplagsub

mv source/$1/*.ir.c source/$1/jplagsub/

#Running JPlag
java -jar jplag-2.12.1-SNAPSHOT-jar-with-dependencies.jar -l c/c++ -r submission/$1/jplag/ -s source/$1/jplagsub/
