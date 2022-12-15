CC = gcc
CFLAGS = -ansi -Wall
SRCDIR = ./src
ODIR = ./out
OFILES = $(subst src/,out/,$(subst .c,.o,$(shell find $(SRCDIR)/ -type f)))
EXE = vernam

but : $(EXE)

$(ODIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

$(EXE) : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

clean :
	-rm -rf $(ODIR)

.PHONY : but clean
