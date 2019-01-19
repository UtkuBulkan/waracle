CFLAGS := -fPIC -O3 -g -Wall -DLOG_LEVEL=0
CC := g++
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
MAJOR := 1
MINOR := 0
NAME := waracle
VERSION := $(MAJOR).$(MINOR)
INC = -I./lib -I./inc

lib: lib$(NAME).so.$(VERSION)

test: $(NAME)_test
	LD_LIBRARY_PATH=. ./$(NAME)_test

$(NAME)_test: lib$(NAME).so ./src/$(NAME)_test.cpp
	$(CC) ./src/$(NAME)_test.cpp -I./lib -I./inc -L. -l$(NAME) -o $@

lib$(NAME).so: lib$(NAME).so.$(VERSION)
	ldconfig -v -n .
	ln -sf lib$(NAME).so.$(VERSION) lib$(NAME).so

lib$(NAME).so.$(VERSION): lib/libwaracle.cpp lib/filebase.cpp lib/fileinput.cpp lib/fileoutput.cpp
	$(CC) $(LDFLAGS) $(CFLAGS) $(INC) $^ -o $@

clean:
	$(RM) $(NAME)_test *.o *.so*
