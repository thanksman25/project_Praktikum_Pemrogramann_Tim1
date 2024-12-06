all: projek1 projek2
projek1 : projek1.c
	gcc -o program1 projek1.c fungsiprojek1.c

projek2 : projek2.c
	gcc -o program2 projek2.c
