#-------------------------------------------------------------------COLORS---------------------------------------------------------------------------------------------

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

# --------------------------------------------------------------------VARS ---------------------------------------------------------------------------------------------

NAME			= libft.a                    										# name of the programm

CC				= gcc                        										# compiler

FLAGS			= -Wall -Wextra -Werror      										# flags

RM				= rm -f                      										# remove 

LIBC 			= ar rcs					 										# creates library archive

# -----------------------------------------------------------------SOURCE FILES ----------------------------------------------------------------------------------------

SOURCES			= 	ft_atoi.c \
                	ft_bzero.c \
                	ft_calloc.c \
                	ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
                	ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
                	ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
                	ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
                	ft_strtrim.c \
                	ft_isalnum.c \
                	ft_isprint.c \
                	ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
                	ft_tolower.c \
					ft_toupper.c \

OBJS	   		 = $(SOURCES:.c=.o)       	 										# trasnforms all the ".c" files into ".o" (objects)

# -------------------------------------------------------------------- RULES -------------------------------------------------------------------------------------------

.c.o:		
			@$(CC) $(FLAGS) -c -I. $< -o $(<:.c=.o)

		
$(NAME):	$(OBJS)                                                                      
			@$(LIBC) $(NAME) $(OBJS)
			@echo $(BGreen)√$(Color_Off)$(BBlue)Libft Has Been Compiled!$(Color_Off);

all:	    $(NAME)																	# will execute NAME rule

clean: 																				# remove all .o
			$(RM) $(OBJS) 
			@echo "...clean succeeded, all the '.o' has been removed!"
														         
fclean: clean                            											# force remove NAME
			$(RM) $(NAME)
			@echo "...fclean succeeded, 'libft.a' has been removed!"


re: fclean all																		# rule to recompile MAKEFILE (will remove everything and allows to recompile again)
			@echo "...recompile succeeded!"		

# ----------------------------------------------------------------------PHONY --------------------------------------------------------------------------------------------

.PHONY: all clean fclean re             											# in phony section we need to include all used rules
