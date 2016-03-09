CC = gcc
NAME = libhtab
LIB_NAME = $(NAME).a
CFLAGS = -Wextra -Wall -Werror

SOURCES_FOLDER = sources
TEST_FORDER = test
INCLUDES_FOLDER = includes
OBJECTS_FOLDER = ../.objects/$(NAME)

DEPENDENCIES = libft \
								liblist

SOURCES_DEPENDENCIES = $(foreach dep,$(DEPENDENCIES), ../$(dep)/$(dep).a)

LIBRARIES = $(foreach dep,$(DEPENDENCIES), -L../$(dep)/ -$(subst lib,l,$(dep)))
INCLUDES_LIBRARIES = $(foreach dep,$(DEPENDENCIES),-I ../$(dep)/includes)
HEADERS_LIBRARIES = $(foreach dep,$(DEPENDENCIES),../$(dep)/includes/$(dep).h)
MAKE_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make -C ../$(dep);)

INCLUDES = $(NAME).h

SOURCES = create_htab.c \
					htab_set.c \
	  			htab_get.c \

OBJECTS = $(SOURCES:%.c=%.o)

all: init $(LIB_NAME)

# dev: init $(MAIN_OBJECT) $(LIB_NAME)

ifdef DEPENDENCIES
init: $(SOURCES_DEPENDENCIES)
	$(MAKE_LIBRARIES)
	@mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)

$(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.c $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES))
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) $(INCLUDES_LIBRARIES) -o $@ -c $<
endif

ifndef DEPENDENCIES
init:
	@mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)

$(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.c $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES))
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $@ -c $<
endif

$(MAIN_OBJECT): $(MAIN)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $(MAIN_OBJECT) -c $(MAIN)

$(LIB_NAME): $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	ar rc $(LIB_NAME) $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	ranlib $(LIB_NAME)

clean:
	rm -f $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	rm -f $(MAIN_OBJECT)
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
