NAME	= add-nbo
CC		= gcc
RM		= rm -rf
SRCS	= add-nbo.c
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $<  -o $@

$(OBJS) : $(SRCS)
	$(CC) $< -c -o $@

clean :
	$(RM) $(OBJS) $(NAME)

.PHONY: all clean
