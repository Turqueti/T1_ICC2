all:
	gcc *.c *.h -o out -g

Wall:
	gcc *.c *.h -o out -g -Wall

allc:
	gcc *.c *.h -o out -g

debug:
	gcc *.c *.h -o out -g -Wall;
	valgrind ./out < 1.in

exec:
	gcc *.c *.h -o out -g -Wall;
	./out < 1.in;
	
	