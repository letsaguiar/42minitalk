CC := gcc
CFLAGS := -Wall -Wextra -Werror
CLIBS := -Llibs -lft -lftprintf
CINCLUDES := -Iincludes

SERVER_FILES := src/server.c
CLIENT_FILES := src/client.c

SERVER := server
CLIENT := client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_FILES)
	$(CC) $(CFLAGS) $(SERVER_FILES) -o $(SERVER) $(CINCLUDES) $(CLIBS)

$(CLIENT): $(CLIENT_FILES)
	$(CC) $(CFLAGS) $(CLIENT_FILES) -o $(CLIENT) $(CINCLUDES) $(CLIBS)

clean:
	rm -f $(SERVER) $(CLIENT)

re: clean all