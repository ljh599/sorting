main: main.o mergesort.o quicksort.o heapsort.o
	gcc -o main main.o mergesort.o quicksort.o heapsort.o
main.o: main.c
	gcc -c main.c
mergesort.o: mergesort.c
	gcc -c mergesort.c
quicksort.o: quicksort.c 
	gcc -c quicksort.c
heapsort.o: heapsort.c
	gcc -c heapsort.c
clean:
	rm  main.o main quicksort.o mergesort.o heapsort.o database1.txt database2.txt
