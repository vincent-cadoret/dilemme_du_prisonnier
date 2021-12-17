CXX = gcc

CLIENT_SRC = ./src/client/sources/*.c
CLIENT_OBJ = $(CLIENT_SRC:.cc=.o)

SERVER_SRC = ./src/server/sources/*.c
SERVER_OBJ = $(SERVER_SRC:.cc=.o)

EXEC_SERVER = ./build/Server
EXEC_SERVER = ./build/Client
GREEN_COLOR=tput setaf 2
BOLD=tput bold

CFLAGS= -DDEBUG
LFLAGS= -lconfig -pthread

$(EXEC_SERVER): $(SERVER_OBJ)
    $(CXX) $(CFLAGS) -o $@ $(SERVER_OBJ) $(LBLIBS) $(LFLAGS)

$(EXEC_SERVER): $(CLIENT_OBJ)
    $(CXX) $(CFLAGS) -o $@ $(CLIENT_OBJ) $(LBLIBS) $(LFLAGS)

all: $(EXEC_SERVER) $(EXEC_SERVER)