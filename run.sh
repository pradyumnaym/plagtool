#!/bin/sh
export PATH="/home/pradyumna/RELEASE/BIN_LINUX:$PATH"
python3 remove_include.py $1 #removes include statements in the C files

cd sources/$1/

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
mkdir submissions/$1
mkdir submissions/$1/moss/
python3 m.py $1

mkdir sources/$1/jplagsub

mv sources/$1/*.ir.c sources/$1/jplagsub/

#Running JPlag
java -jar jplag-2.12.1-SNAPSHOT-jar-with-dependencies.jar -l c/c++ -r submissions/$1/jplag/ -s sources/$1/jplagsub/
