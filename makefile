CC=gcc
route=

all: go_thread_handler.o thread_handler.o  wave_generator.o util.o
	@$(CC) go_thread_handler.o thread_handler.o wave_generator.o util.o -o wave -Wall -lpthread -lm -I.
	@rm go_thread_handler.o thread_handler.o wave_generator.o util.o
	@echo "Compilación terminada"

go_thread_handler.o: $(route)go_thread_handler.c
	@$(CC) -c $(route)go_thread_handler.c

thread_handler.o: $(route)thread_handler.c
	@$(CC) -c $(route)thread_handler.c

wave_generator.o: $(route)wave_generator.c
	@$(CC) -c $(route)wave_generator.c

util.o:	$(route)util.c
	@$(CC) -c $(route)util.c