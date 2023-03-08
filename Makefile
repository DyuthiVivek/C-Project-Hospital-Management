# executable name
EXE = hospital

# C compiler
CC = gcc
LD = gcc

# C flags
CFLAGS = -Iinclude

# build directories
SRC = .
SRC1 = dyuthi
SRC2 = swetha
SRC3 = sukeerthi
SRC4 = akshaya
SRC5 = snigdha_shreeya

SOURCES := $(wildcard $(SRC1)/*.c) \
	   $(wildcard $(SRC2)/*.c) \
	   $(wildcard $(SRC3)/*.c) \
	   $(wildcard $(SRC4)/*.c) \
	   $(wildcard $(SRC5)/*.c)

OBJECTS := \
	$(patsubst $(SRC)/%.c, $(SRC)/%.o, $(wildcard $(SRC)/*.c)) \
	$(patsubst $(SRC1)/%.c, $(SRC1)/%.o, $(wildcard $(SRC1)/*.c)) \
	$(patsubst $(SRC2)/%.c, $(SRC2)/%.o, $(wildcard $(SRC2)/*.c)) \
	$(patsubst $(SRC3)/%.c, $(SRC3)/%.o, $(wildcard $(SRC3)/*.c)) \
	$(patsubst $(SRC4)/%.c, $(SRC4)/%.o, $(wildcard $(SRC4)/*.c)) \
	$(patsubst $(SRC5)/%.c, $(SRC5)/%.o, $(wildcard $(SRC5)/*.c))

# compile C source
COMPILE.c = $(CC) $(CFLAGS) -c -o $@

# link objects
LINK.o = $(LD) $(OBJECTS) -o $@

all: $(EXE)

$(EXE): $(OBJECTS)
	$(LINK.o)

$(SRC)/%.o:	$(SRC)/%.c
	$(COMPILE.c) $<

clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXE)
