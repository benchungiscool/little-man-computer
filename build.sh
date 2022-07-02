gcc -Wall -pedantic-errors -c src/compiler.c
gcc -Wall -pedantic-errors -c src/run.c
gcc -Wall -pedantic-errors -o lmc compiler.o run.o
./lmc -f example.lmc
