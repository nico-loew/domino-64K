OBJ_PATH = Obj/
COMMON_PATH = ../Common

LIBS_WINDOWS = -lglew32 -lmingw32 -lopengl32 -lSDL2main -lSDL2 -lSDL2_mixer 
LIBS_UBUNTU = -lGL -lGLEW -lSDL2 -lSDL2_mixer

LIBS = $(LIBS_WINDOWS)
FLAGS = -W -Wall -std=c++11 -I $(COMMON_PATH)

SOURCES = Main.cpp
HEADERS = 

OBJS = $(SOURCES:%.cpp=$(OBJ_PATH)%.o)
VPATH = src:$(COMMON_PATH)

all: $(OBJS)
	g++ $(OBJS) $(LIBS)

$(OBJ_PATH)%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@ $(FLAGS)

clean:
	rm -rf $(OBJ_PATH)*.o
