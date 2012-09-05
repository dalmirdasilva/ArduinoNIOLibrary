/**
 * Arduino NIO
 * 
 * Buffer.cpp
 */

#ifndef __ARDUINO_NIO_BUFFER_CPP__
#define __ARDUINO_NIO_BUFFER_CPP__ 1

#include "Buffer.h"

Buffer::Buffer(unsigned int mark, unsigned int pos, unsigned int lim, unsigned int cap) {
    this->cap = cap;
    this->markpos = mark;
    if (mark > 0) {
        this->marked = true;
    } else {
        this->marked = false;
    }
    setPosition(pos);
    setLimit(lim);
}

unsigned int Buffer::getCapacity() {
    return cap;
}

unsigned int Buffer::getPosition() {
    return pos;
}

void Buffer::setPosition(unsigned int pos) {
    this->pos = pos;
    if (marked && markpos > pos) {
        marked = false;
    }
}

unsigned int Buffer::getLimit() {
    return lim;
}

void Buffer::setLimit(unsigned int lim) {
    if (lim > cap) {
        return;
    }
    this->lim = lim;
    if (pos > lim) {
        pos = lim;
    }
    if (marked && markpos > lim) {
        marked = false;
    }
}

void Buffer::mark() {
    markpos = pos;
    marked = true;
}

void Buffer::reset() {
    if (marked) {
        pos = markpos;
    }
}

void Buffer::clear() {
    pos = 0;
    lim = cap;
    markpos = 0;
}

void Buffer::flip() {
    lim = pos;
    pos = 0;
    marked = false;
}

void Buffer::rewind() {
    pos = 0;
    marked = false;
}

unsigned int Buffer::getRemaining() {
    return lim - pos;
}

bool Buffer::hasRemaining() {
    return pos < lim;
}

#endif /* __ARDUINO_NIO_BUFFER_CPP__ */
