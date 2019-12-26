# TotalJustice

CC			:= gcc
CFLAGS		:= -Wall -O3

TARGET		:= $(notdir $(CURDIR))
SOURCE		:= source
#INCLUDE		:= include

CFILES 		:= $(wildcard $(SOURCE)/*.c)
#HFILES		:= $(wildcard $(INCLUDE)/*.h)
#OBJECT 		:= $(CFILES:.c=.o)


all: $(CFILES)
	@echo building...
	$(CC) $(CFLAGS) $(CFILES) $(HFILES) -o $(TARGET)

clean:
	@echo cleaning...
	rm $(TARGET).exe

run:
	@echo running...
	./$(TARGET).exe