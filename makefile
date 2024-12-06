all: project1 project2
project1 : project1.c
	gcc -o program1 project1.c fungsiproject1.c

project2 : project2.c
	gcc -o program2 project2.c
