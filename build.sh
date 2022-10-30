COMPILER="g++"
ARGS="-std=c++20"
SRC="./src/*.cpp"
INCLUDE="./include"
BINARY="./bin/prog"
LIBS="-lmingw32 -lSDL2main -lSDL2"

SDL_INCLUDE="./include/SDL_include"
SDL_LIBS="./src/SDL_lib"

COMPILE="${COMPILER} ${ARGS} ${SRC} -I ${INCLUDE} -I ${SDL_INCLUDE} -L ${SDL_LIBS} -o ${BINARY} ${LIBS}"

echo ${COMPILE}

eval $COMPILE

echo
echo "Compilation complete"
echo

#./bin/prog.exe
