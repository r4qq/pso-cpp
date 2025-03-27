CXX = clang++
CXXFLAGS = -Wall -Werror -std=c++17

SRCDIR = ./src
BINDIR = ./bin
OBJDIR = ./obj

TARGET = ./bin/test

SRCS = $(SRCDIR)/main_pso.cpp $(SRCDIR)/Point.cpp $(SRCDIR)/Pso.cpp
OBJS = $(OBJDIR)/main_pso.o $(OBJDIR)/Point.o $(OBJDIR)/Pso.o

all: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@


