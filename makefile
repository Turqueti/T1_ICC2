all:
	gcc *.c -o out -g

Wall:
	gcc *.c -o out -g -Wall

allc:
	gcc *.c -o out -g

debug:
	gcc *.c -o out -g -Wall;
	valgrind ./out < 1.in

exec:
	gcc *.c -o out -g -Wall;
	./out < 1.in;
	
	