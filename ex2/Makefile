CC=g++

LIBHDRS=general.h uthreads.h thread.h priorityList.h
LIBSRC=uthreads.cpp thread.cpp priorityList.cpp
LIBOBJ=$(LIBSRC:.cpp=.o)

#remove before submission
TESTSRC = main.cpp
TESTOBJ = $(TESTSRC:.cpp=.o)
TEST = test

INCS=-I.
CFLAGS = -std=c++11 -Wall -g -O0 $(INCS)
LOADLIBES = -L./

LIB = libuthreads.a
TARGETS = $(LIB)

TAR=tar
TARFLAGS=-cvf
TARNAME=ex2.tar
TARSRCS=$(LIBSRC) $(LIBHDRS) Makefile README

all: $(TARGETS)

$(TARGETS):	$(LIBOBJ)
	$(AR) $(ARFLAGS) $@ $^

#remove before submission
$(TEST): $(TESTSRC) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

#remove TESTOBJ TEST before submission
clean:
	$(RM) $(TARGETS) $(OSMLIB) $(OBJ) $(LIBOBJ) $(TESTOBJ) $(TEST) $(TARNAME) *~ *core

depend:
	makedepend -- $(CFLAGS) -- $(SRC) $(LIBSRC)

tar:
	$(TAR) $(TARFLAGS) $(TARNAME) $(TARSRCS)