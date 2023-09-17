NAME := sort
CC := g++
CFLAGS := -Wall -Werror -Wextra -lrt
INCLS := -I./incls/
SRCS := ./srcs/main.cpp ./srcs/Sorter.cpp ./srcs/Parser.cpp

.PHONY : all re clean

all :
	$(CC) $(CFLAGS) $(SRCS) $(INCLS) -o $(NAME)

clean :
	rm -rf $(NAME)

re : clean all