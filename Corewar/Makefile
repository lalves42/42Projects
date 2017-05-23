#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 18:45:02 by lalves            #+#    #+#              #
#    Updated: 2017/02/17 19:25:04 by akopera          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CORR_FILES = ./VM ./Assembler

.PHONY: all clean fclean re bonus

all: ./Assembler/asm ./VM/corewar

./Assembler/asm:
	$(MAKE) -C ./Assembler

./VM/corewar:
	$(MAKE) -C ./VM

bonus: ./Assembler/asm
	$(MAKE) -C ./VM bonus

clean:
	$(MAKE) -C ./Assembler clean
	$(MAKE) -C ./VM clean

fclean: clean
	$(MAKE) -C ./Assembler fclean
	$(MAKE) -C ./VM fclean

re: fclean all
