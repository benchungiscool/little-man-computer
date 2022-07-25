./run
valgrind --tool=memcheck --track-origins=yes --leak-check=full ./lmc -f example.lmc
rm vgcore.*
