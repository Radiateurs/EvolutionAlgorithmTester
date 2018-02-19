#=======
#
# Created by Pierre-Marie
# The 30th of January 2018
#
#=======

CC =		g++

RM =		rm -rf

CP =		cp

NAME =		GenerateAgents

SOURCE =	./source/Main.cpp		\
		./source/Agent.cpp		\
		./source/DeveloppingAgent.cpp	\
		./source/Population.cpp

OBJ =		$(SOURCE:.cpp=.o)

FINC =		-I./include/

CPPFLAGS =	-W -Werror -Wall -Wextra $(FINC) -std=c++11

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(FINC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

dbg:		CPPFLAGS += -g
dbg:		re

.PHONY:		all $(NAME) clean fclean re
