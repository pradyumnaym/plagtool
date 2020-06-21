CC = g++

CFLAGS = -g

FLAG_1 = -m32

LANCE2_H = ../INCL/lance2.h

OBJ = myapp.o

LIB = ../LIB_LINUX/liblance2.a

PRG = myapp 

all:	obj exe

obj:	$(OBJ)

exe:	$(PRG)	


$(PRG):	$(OBJ) $(LIB)
	$(CC) -static $(FLAG_1) $(OBJ) $(LIB) -o $(PRG)
	chmod 755 $(PRG)
	strip $(PRG)

myapp.o: myapp.c $(LANCE2_H) 
	$(CC) $(CFLAGS) $(FLAG_1) -c myapp.c -o myapp.o

clean:
		rm -f $(OBJ) $(PRG)
