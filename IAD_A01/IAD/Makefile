CC = cc 
LD = cc 
LDFLAGS = -o
COMPILE = -c 
STD_HEADERS = headers.h
OBJ = Server.o Client.o Validation.o Main.o 
EXE = final

$(EXE): $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) $(EXE)

Server.o: Server.c 
	$(CC) $(COMPILE) Server.c

Client.o: Client.c
	$(CC) $(COMPILE) Client.c

Validation.o: Validation.c headers.h
	$(CC) $(COMPILE) Validation.c

Main.o: Main.c Server.c Validation.c Client.c headers.h
	$(CC) $(COMPILE) Main.c

clean:
	rm *.o $(EXE)
