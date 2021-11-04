CC=g++
CXXFLAGS= -Wall -std=c++14

UT		:= unitTests
APP		:= magicSquares

PRJDIR	:= .
SRCDIR	:= source
OBJDIR	:= .build

SRC_OBJ	:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))
UT_OBJ	:= $(patsubst $(PRJDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(PRJDIR)/tests.cpp))
APP_OBJ	:= $(patsubst $(PRJDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(PRJDIR)/main.cpp))


.PHONY: all clean

all:	bdir $(UT) $(APP)

bdir:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -o $@ $< -c $(CXXFLAGS)

$(OBJDIR)/%.o: $(PRJDIR)/%.cpp
	$(CC) -o $@ $< -c $(CXXFLAGS)

$(UT): $(UT_OBJ) $(SRC_OBJ)
	$(CC) -o $@ $^

$(APP): $(APP_OBJ) $(SRC_OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJDIR)/*.o $(UT) $(APP)
	rm -rf $(OBJDIR)

print_ut: $(UT_OBJ)
	ls -la $?

