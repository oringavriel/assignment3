CC= gcc
AR= ar
FLAGS= -Wall


all: StrList libmystr.a 


StrList : Main.o libmystr.a
	$(CC) $(FLAGS) -o StrList Main.o libmystr.a


libmystr.a: StrList.o
	$(AR) rcs libmystr.a StrList.o
	ranlib libmystr.a


Main.o: Main.c
	$(CC) $(FLAGS) -fPIC -c Main.c


StrList.o: StrList.c
	$(CC) $(FLAGS) -fPIC -c StrList.c


clean:
	rm  *.o StrList libmystr.a 