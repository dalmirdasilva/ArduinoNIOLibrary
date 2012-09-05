/**
 * Arduino NIO
 * 
 * ArrayByteBuffer.cpp
 */

#ifndef __ARDUINO_NIO_ARRAY_BYTE_BUFFER_CPP__
#define __ARDUINO_NIO_ARRAY_BYTE_BUFFER_CPP__ 1

#include "ArrayByteBuffer.h"

ArrayByteBuffer::ArrayByteBuffer(unsigned char* buf, unsigned int len) : ByteBuffer(0, 0, len, len), buf(buf) {
}

unsigned char ArrayByteBuffer::get() {
    if (pos < lim) {
        return buf[pos++];
    }
    return 0;
}

void ArrayByteBuffer::put(unsigned char b) {
    if (pos < lim) {
        buf[pos++] = b;
    }
}

unsigned char ArrayByteBuffer::get(unsigned int index) {
    if (index < lim) {
        return buf[index];
    }
    return 0;
}

void ArrayByteBuffer::put(unsigned int index, unsigned char b) {
    if (index < lim) {
        buf[index] = b;
    }
}

bool ArrayByteBuffer::isReadOnly() {
    return false;
}

bool ArrayByteBuffer::hasArray() {
    return true;
}

unsigned char* ArrayByteBuffer::getArray() {
    return buf;
}

#endif /* __ARDUINO_NIO_ARRAY_BYTE_BUFFER_CPP__ */
