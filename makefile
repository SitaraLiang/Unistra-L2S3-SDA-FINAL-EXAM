main : main.o tp_note_2023.o
	gcc -g $^ -o $@
main.o : tp_note_2023.h
tp_note_2023.0 : tp_note_2023.h base.h

%.o:%.c
	gcc -g -c $<

clean:
	rm *.o main

run: main
	./main

valgrind-check: main
	valgrind ./main