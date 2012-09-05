/**
 * Arduino NIO
 * 
 * ByteBuffer.cpp
 */

#ifndef __ARDUINO_NIO_BYTE_BUFFER_CPP__
#define __ARDUINO_NIO_BYTE_BUFFER_CPP__ 1

#include "ByteBuffer.h"

ByteBuffer::ByteBuffer(unsigned int mark, unsigned int pos, unsigned int lim, unsigned int cap) : Buffer(mark, pos, lim, cap) {
}

bool ByteBuffer::get(unsigned char* dst, int off, int len) {
    if (len > getRemaining()) {
        return false;
    }
    unsigned int end = off + len;
    for (int i = off; i < end; i++) {
        dst[i] = get();
    }
    return true;
}

bool ByteBuffer::get(unsigned char* dst, int len) {
    return get(dst, 0, len);
}

bool ByteBuffer::put(unsigned char* src, int off, int len) {
    if (len > getRemaining()) {
        return false;
    }
    unsigned int end = off + len;
    for (unsigned int i = off; i < end; i++) {
        put(src[i]);
    }
    return true;
}

bool ByteBuffer::put(unsigned char* src, int len) {
    return put(src, 0, len);
}

bool ByteBuffer::put(ByteBuffer* src) {
    return put(src, src->getRemaining());
}

bool ByteBuffer::put(ByteBuffer* src, int len) {
    if (src == this) {
        return false;
    }
    unsigned int n = src->getRemaining();
    len = (len > n) ? len : n;
    if (len > getRemaining()) {
        return false;
    }
    for (unsigned int i = 0; i < n; i++) {
        put(src->get());
    }
    return true;
}

#endif /* __ARDUINO_NIO_BYTE_BUFFER_CPP__ */
