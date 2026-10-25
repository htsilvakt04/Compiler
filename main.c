#include "chunk.h"
#include "debug.h"
#include "vm.h"
// 1 * 2 + 3
int main(int argc, char *argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    int constantIdx = addConstant(&chunk, 1.0);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constantIdx, 123);

    constantIdx = addConstant(&chunk, 2.0);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constantIdx, 123);

    writeChunk(&chunk, OP_MULTIPLY, 123);

    constantIdx = addConstant(&chunk, 3.0);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constantIdx, 123);


    writeChunk(&chunk, OP_ADD, 123);
    writeChunk(&chunk, OP_RETURN, 123);
    // disassembleChunk(&chunk, "test chunk");

    /*--- INTERPRETING ---*/
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
}
