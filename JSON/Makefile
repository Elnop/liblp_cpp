.DEFAULT_GOAL := all

NAME := JSON.a

CXX := c++

CXXFLAGS := -std=c++98 -Wall -Wextra -g3 -Werror

SOURCES_DIR := src

SOURCES_SUBDIRS := $(shell find $(SOURCES_DIR) -type d)

SOURCES_NAMES := $(subst $(SOURCES_DIR)/,, $(foreach dir, $(SOURCES_SUBDIRS), $(wildcard $(dir)/*.cpp)))

SOURCES := $(addprefix $(SOURCES_DIR)/, $(SOURCES_NAMES))

OBJECTS_DIR := .obj

OBJECTS_NAMES := $(SOURCES_NAMES:.cpp=.o)

OBJECTS := $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_NAMES))

DEPENDANCIES_DIR := .dep

DEPENDANCIES := $(patsubst %.cpp, $(DEPENDANCIES_DIR)/%.d, $(SOURCES_NAMES))

INCLUDES := inc

AR = ar

AR_FLAGS = -rcs

SHELL := /bin/sh

.SUFFIXES: .cpp .o

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	${AR} ${AR_FLAGS} $@ $(OBJECTS)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp $(INCLU)
	@if [ ! -d "$$(dirname $@)" ] ; then mkdir -p "$$(dirname $@)" ; fi
	@if [ ! -d "$$(dirname $(DEPENDANCIES_DIR)/$*.d)" ] ; \
	then mkdir -p "$$(dirname $(DEPENDANCIES_DIR)/$*.d)" ; fi
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -o $@ -c $< -MD -MF $(DEPENDANCIES_DIR)/$*.d

.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) -r $(OBJECTS_DIR) $(DEPENDANCIES_DIR)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: test
test: all
	@make re -C tester
	@./tester/JSON_tester

.PHONY: testvalg
testvalg: all
	@make re -C tester
	valgrind -q --leak-check=full --leak-check=full --show-leak-kinds=all ./tester/JSON_tester

-include $(DEPENDANCIES)