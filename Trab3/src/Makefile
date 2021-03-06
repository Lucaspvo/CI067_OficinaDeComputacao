# Lines starting with the pound sign are comments.
#
# These are the two options that may need tweaking

EXECUTABLE = agturismo
LINKCC = $(CC)

# You can modify the below as well, but probably
# won't need to.
#

# CC is for the name of the C compiler. CPPFLAGS denotes pre-processor
# flags, such as -I options. CFLAGS denotes flags for the C compiler.
# CXXFLAGS denotes flags for the C++ compiler. You may add additional
# settings here, such as PFLAGS, if you are using other languages such
# as Pascal.

CPPFLAGS = 

LDFLAGS = -lpthread -lm

CC = gcc
CFLAGS = -Wall -o0 -g		# debugging
#CFLAGS = -Wall			# normal 

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
DEPS := $(patsubst %.o,%.d,$(OBJS))

# "all" is the default target. Simply make it point to myprogram.

all: $(EXECUTABLE)

# Define the components of the program, and how to link them together.
# These components are defined as dependencies; that is, they must be
# made up-to-date before the code is linked.

$(EXECUTABLE): $(DEPS) $(OBJS)
	$(LINKCC) $(LDFLAGS) -o $(EXECUTABLE) $(OBJS)
	-mv -f $(EXECUTABLE) ../bin/$(EXECUTABLE)

# Specify that the dependency files depend on the C source files.

%.d: %.c
	$(CC) -M $(CPPFLAGS) $< > $@
	$(CC) -M $(CPPFLAGS) $< | sed s/\\.o/.d/ >> $@

# Specify that all .o files depend on .c files, and indicate how
# the .c files are converted (compiled) to the .o files.

tudo: $(DEPS) $(OBJS)
	$(LINKCC) $(LDFLAGS) -o $(EXECUTABLE) $(OBJS)
	-mv -f $(EXECUTABLE) ../bin/$(EXECUTABLE)

limpa:
	-rm -f $(OBJS) $(DEPS)
faxina:
	-rm -f $(OBJS) $(DEPS) $(EXECUTABLE) ../bin/$(EXECUTABLE)

tar:
	tar -cf trab.tar *.c *.h Makefile
	@echo "trab.tar created"

explain:
	@echo "The following information represents your program:"
	@echo "Final executable name: $(EXECUTABLE)"
	@echo "Source files:     $(SRCS)"
	@echo "Object files:     $(OBJS)"
	@echo "Dependency files: $(DEPS)"

depend: $(DEPS)
	@echo "Dependencies are now up-to-date."

-include $(DEPS)
