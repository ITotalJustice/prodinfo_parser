# TotalJustice

CC			:= gcc
CFLAGS		:= -Wall -O3
CFILES 		:= $(wildcard *.c)
OBJECT 		:= $(CFILES:.c=.o)

TARGET		:= $(notdir $(CURDIR))
#SOURCE		:= source
#INCLUDE	:= include


all: $(CFILES)
	@echo building...
	$(CC) $(CFLAGS) $(CFILES) -o $(TARGET)

clean:
	@echo cleaning...
	rm $(TARGET)
	#rm *.o $(TARGET)

run:
	@echo running...
	./$(TARGET)