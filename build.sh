gcc -Wall -pedantic-errors -c src/compiler.c
gcc -Wall -pedantic-errors -c src/run.c
gcc -Wall -pedantic-errors -o a.out compiler.o main.o
./a.out -f example.lmc
