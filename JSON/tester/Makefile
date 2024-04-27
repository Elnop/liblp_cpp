.DEFAULT_GOAL := all

NAME := JSON_tester

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -g3 #-std=c++98

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

SHELL := /bin/sh

.SUFFIXES: .cpp .o

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) $(OBJECTS) ../JSON.a -o $(NAME)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	@if [ ! -d "$$(dirname $@)" ] ; then mkdir -p "$$(dirname $@)" ; fi
	@if [ ! -d "$$(dirname $(DEPENDANCIES_DIR)/$*.d)" ] ; \
	then mkdir -p "$$(dirname $(DEPENDANCIES_DIR)/$*.d)" ; fi
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) $(OPTFLAGS) -c $< -o $@ -MD -MF $(DEPENDANCIES_DIR)/$*.d

.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) -r $(OBJECTS_DIR) $(DEPENDANCIES_DIR)

.PHONY: re
re: fclean
	$(MAKE)

-include $(DEPENDANCIES)
