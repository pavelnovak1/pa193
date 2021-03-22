#include <stdio.h>
#include <stdlib.h>
void bufferOverflow(int buflen, char* w){
        int intArray[10];
        intArray[20] = 0;
        for( int i = 0; i < buflen; i++){
                printf("%x", intArray[i]);
                intArray[i] = *w;
        }
}
int* heapOverflowAndMemoryLeak(int buflen){
        int* dynArrayMemoryLeak = new int[10];
        int* dynArrayFreedMemory = new int[10];
        dynArrayMemoryLeak[20] = 4;
        for( int i = 0; i < buflen; i++ ){
                dynArrayMemoryLeak[i] = i;
                dynArrayFreedMemory[i] = i;
        }
        int* ret = dynArrayFreedMemory;
        delete[](dynArrayFreedMemory);
        return ret;
}
void typeOverflow(int buflen){
        int array[5];
        for(unsigned char i = 4;i <= 0;i--){array[i] = 1;}
}
void outByOneAndUninitialized(int buflen){
        int uninitialized;
        int* array = new int[buflen];
        for( int i = 0; i <= buflen; i++){
                if(uninitialized < buflen){array[i] = 1;}
                else { array[i] = 2;}
        }
        delete(array);
}
int main(int argc, char* argv[]){
        int bufLen = atoi(argv[1]);
        bufferOverflow(bufLen, argv[2]);
        typeOverflow(bufLen);
        outByOneAndUninitialized(bufLen);
        int* pointer = heapOverflowAndMemoryLeak(bufLen);
        *pointer = 0;
        delete[](pointer);
}
