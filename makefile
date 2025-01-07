.PHONY: run compile clean
compile: control.o play.o boardMgmt.o roundMgmt.o
	@gcc -o control control.o boardMgmt.o roundMgmt.o
	@gcc -o play play.o boardMgmt.o roundMgmt.o
control.o: control.c boardMgmt.h roundMgmt.h
	@gcc -c control.c
play.o: play.c boardMgmt.h roundMgmt.h
	@gcc -c play.c
boardMgmt.o: boardMgmt.c
	@gcc -c boardMgmt.c
roundMgmt.o: roundMgmt.c
	@gcc -c roundMgmt.c
control:
	@./control
play:
	@./play
clean:
	@rm -rf *.o control play
