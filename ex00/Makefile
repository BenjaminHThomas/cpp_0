# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 07:42:06 by bthomas           #+#    #+#              #
#    Updated: 2024/08/16 16:50:22 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= megaphone

SRC			= megaphone.cpp

OBJDIR		= objs
OBJS		= $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

CFLAGS		= -Wall -Werror -Wextra -std=c++98
COMPILER	= c++

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: %.cpp
	@$(COMPILER) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing program..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
