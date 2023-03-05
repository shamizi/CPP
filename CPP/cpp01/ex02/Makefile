# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:26:39 by shamizi           #+#    #+#              #
#    Updated: 2022/11/23 16:04:43 by shamizi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

SRCS = main.cpp 

OBJS = ${SRCS:.cpp=.o}


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

%.o: %.cpp

	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
