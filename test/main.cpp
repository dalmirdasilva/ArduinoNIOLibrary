#include <stdint.h>
#include <stdio.h>

#include <Buffer.cpp>
#include <ByteBuffer.cpp>
#include <ArrayByteBuffer.cpp>

void testArrayByteBuffer() {
    bool error = false;
    unsigned char byteArray[100];
    ArrayByteBuffer abb(byteArray, 100);
    abb.put(1);
    abb.put(2);
    abb.put(3);
    if (byteArray[0] != 1 || byteArray[1] != 2 || byteArray[2] != 3) {
        error = 1;
    }
    abb.clear();
    abb.put(0xaa);
    abb.put(0xbb);
    if (byteArray[0] != 0xaa || byteArray[1] != 0xbb) {
        error = 1;
    }
    abb.mark();
    abb.put(0x00);
    abb.put(0x38);
    abb.put(0x94);
    abb.put(0x66);
    abb.reset();
    if (abb.get() != 0x00) {
        error = 1;
    }
    if (abb.get() != 0x38) {
        error = 1;
    }
    if (abb.get() != 0x94) {
        error = 1;
    }
    if (abb.get() != 0x66) {
        error = 1;
    }
    abb.reset();
    abb.put(0xf0);
    if (byteArray[2] != 0xf0) {
        error = 1;
    }
    abb.put(70, 0xfa);
    if (byteArray[70] != 0xfa) {
        error = 1;
    }
    abb.put(0x1a);
    if (byteArray[3] != 0x1a) {
        error = 1;
    }
    if (error) {
        printf("(F) ByteArrayOutputStream failed.\n");
    } else {
        printf("(*) ByteArrayOutputStream passed.\n");
    }
}


int main() {
    testArrayByteBuffer();
    return 0;
}
