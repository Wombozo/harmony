EXE= harmony
CP=g++

SRC_PATH = src
OBJ_PATH = obj
CPPFLAGS = -Iinclude

SRC_FILES = main.cpp \
            Note.cpp \
			errors.cpp \
			NaturalNote.cpp \
			AlteredNote.cpp \
			SharpNote.cpp \
			FlatNote.cpp \
			DblFlatNote.cpp \
			DblSharpNote.cpp \
			Interval.cpp \
			Scale.cpp \
			Mode.cpp \
			utils.cpp  \
			user.cpp 

OBJ_NAME = $(SRC_FILES:.cpp=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m


all: $(EXE)

$(EXE): $(OBJ)
	@$(CP) $@ $(OBJ) && echo "\n$(GREEN)$@ Successfully created$(WHITE)"

	$(CP) -o $@ $^

$(OBJ_PATH)/%.o: src/%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CP) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

clean:
	@rm -f $(OBJ) && echo "$(RED)objects successfully deleted$(WHITE)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

Eclean : clean
	@rm -f $(EXE) && echo "$(RED)$(NAME) deleted$(WHITE)"

.PHONY : all clean Eclean
