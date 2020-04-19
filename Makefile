CC= gcc
CFLAGS= -W -Wall
TARGET= market
OBJECTS= product.o manager.o market.c
DTARGET= market_debug

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET): $(OBJECTS)
	$(CC) $(CLFAGS) -DEBUG -O $@ $^

clean :
	rm *.o market

clean_txt:
	rm product.txt
