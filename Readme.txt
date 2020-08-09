para crear objeto librería: gcc -c libreria.c -o libreria.o
para crear librería: ar -rv liblibreria.a libreria.o
para compilar y crear ejecutable: gcc test.c liblibreria.a test