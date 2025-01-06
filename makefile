.PHONY: run compile clean
compile main: main.o boardMgmt.o roundMgmt.o
	@gcc -o main main.o boardMgmt.o roundMgmt.o
main.o: main.c boardMgmt.h roundMgmt.h
	@gcc -c main.c
boardMgmt.o: boardMgmt.c
	@gcc -c boardMgmt.c
roundMgmt.o: roundMgmt.c
	@gcc -c roundMgmt.c
run:
	@./main
clean:
	@rm -rf *.o main
