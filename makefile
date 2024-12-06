all: project1 project2
projek1 : project1.c
	gcc -o program1 project1.c fungsiproject1.c

projek2 : project2.c
	gcc -o program2 project2.c
