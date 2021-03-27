C=gcc

.PHONY: all
all: main1 main2 main3

# task3
main3: libHello.so hello_ariel.h main1_3.c
	$(C) main1_3.c -fPIC -ldl -o main3

# task2
main2: libHello.so
	$(C) main1_2.c -L. -l Hello -o main2
	export LD_LIBRARAY_PATH=.

	
libHello.so: hello_ariel.h hello_ariel.c
	$(C) -shared hello_ariel.c -fPIC -o libHello.so

# task1	
main1: main1.o hello.o
	$(C) main1.o hello.o -o main1

main1.o: main1_1.c hello_ariel.h
	$(C) -c main1_1.c -o main1.o
	
hello.o: hello_ariel.c hello_ariel.h
	$(C) -c hello_ariel.c -o hello.o
	

	
.PHONY: clean
clean:
	rm -f *.o *.out *.so main1 main2 main3
