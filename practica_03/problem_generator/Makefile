# Compilation settings 
STD = -std=c++17
FLAGS = -Wall -Wextra
GCC = g++ $(STD) $(FLAGS)
OUT = -o generator 
# Files to compile 
 
MAIN = main.cpp  
SRC = $(MAIN) src/generator.cpp  
INCLUDE = 
FILES = $(SRC) include/generator.h 

# Rules 
all: main 

main:  $(FILES)
	$(GCC) $(SRC) $(OUT) 

clean:
	rm generator 
