# Build Output Name
NAME = fine

# Output Directories
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj
INSTALL = /usr/bin

# Output Files
EXE = $(BINDIR)/$(NAME)
OBJ = app.o fine.o functions.o globals.o
OPATHS = $(addprefix $(OBJDIR)/,$(OBJ))

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -c -o $@
LDFLAGS = -Wall -Wextra
RELEASEFLAGS = -O2
DEBUGFLAGS = -g -O0 -DDEBUG

all: CFLAGS += $(RELEASEFLAGS)
all: configure
all: $(EXE)

debug: CFLAGS += $(DEBUGFLAGS)
debug: configure
debug: $(EXE)

configure:
	mkdir -p $(BINDIR) $(OBJDIR)

$(EXE): $(OPATHS)
	$(CC) $(LDFLAGS) $(OPATHS) -o $@

$(OBJDIR)/app.o: app.h
	$(CC) $(CFLAGS) app.c

$(OBJDIR)/fine.o: fine.h
	$(CC) $(CFLAGS) fine.c

$(OBJDIR)/functions.o: functions.h
	$(CC) $(CFLAGS) functions.c

$(OBJDIR)/globals.o: globals.h
	$(CC) $(CFLAGS) globals.c

clean:
	mkdir -p $(OBJDIR) && rm -r $(OBJDIR)

rebuild: clean
rebuild: all

rebuild-dbg: clean
rebuild-dbg: debug

delete: erase
erase:
	mkdir -p $(BUILDDIR) && rm -r $(BUILDDIR)

install:
	cp $(EXE) $(INSTALL)

