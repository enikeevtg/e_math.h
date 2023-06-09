# utilities
CC = gcc
AR = ar rs
RAN = ranlib
RM = rm -rf
MK = mkdir -p

# utilities options
CF = -Wall -Werror -Wextra
STD = -std=c11 -pedantic
ASAN = -g -fsanitize=address

# filenames
SRCDIR = ./e_math_src/
OBJDIR = ./e_math_obj/
SRC = $(wildcard $(SRCDIR)*.c)
OBJ = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))
TARGET = e_math.a
TEST = libtest

all: clean test e_math.a gcov_report

# LIBRARY BUILDING
$(TARGET): objects 
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library e_math.a \033[0;32msuccess\033[0m"

objects: objdir $(OBJ) OBJ_SUCCESS

objdir:
	@$(MK) $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CF) -c $^ -o $@

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccsess\033[0m"
# END OF LIBRARY BUILDING

# UNIT-TESTS
test: $(TARGET)
	$(CC) $(CF) $(STD) $(ASAN) main.c -L. $(TARGET) -o $(EXE)

# TESTS COVERING REPORT
gcov_report:

# SERVICE
style:
	clang-format -style=google -n *.h *.c
	clang-format -style=google -n $(SRCDIR)*.h $(SRCDIR)*.c

tostyle:
	clang-format -style=google -i *.h *.c
	clang-format -style=google -i $(SRCDIR)*.h $(SRCDIR)*.c

fclean:
	@$(RM) $(OBJDIR)
	@echo "full clean: $(OBJDIR) \033[0;31mdeleted\033[0m"
	@$(RM) $(TEST)
	@echo "full clean: $(TEST) \033[0;31mdeleted\033[0m"
	@$(RM) $(TARGET)
	@echo "full clean: $(TARGET) \033[0;31mdeleted\033[0m"
