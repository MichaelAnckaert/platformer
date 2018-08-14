# Specify which files to compile for our project
OBJS = capp.cpp sprite.cpp actor.cpp 

# Specify the name of our executable
OBJ_NAME = platformer

# Target that compiles our executable
all: $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -o $(OBJ_NAME)
