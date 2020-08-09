Para crear objeto libreria.o			: gcc -c libreria.c
Para crear objeto test.o.   			: gcc -c test.c
Para crear ejecutable                           : gcc -o ejecutable libreria.o test.o
Para ejecutar ejecutable desde línea de comandos: ./ejecutable 
(Mejor hacer doble click sobre el fichero ejecutable desde finder para ejecutar

-------------------------------------------
USO DEL PROGRAMA

	1) En primer lugar se probará la función Head
		1.1) Introducimos primera línea y cuando terminemos pulsamos enter
		1.2) Introducimos segunda línea y cuando terminamos pulsamos enter
		...
		1.N) Introducimos n-ésima línea y cuando terminemos pulsamos enter
	2) Cuando no queramos introducir más líneas pulsamos control + D

--------------------------------------------------------------------------------------------------
para crear objeto librería: gcc -c libreria.c -o libreria.o
para crear librería: ar -rv liblibreria.a libreria.o
para compilar y crear ejecutable: gcc test.c liblibreria.a test