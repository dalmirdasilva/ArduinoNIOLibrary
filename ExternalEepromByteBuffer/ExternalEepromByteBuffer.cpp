/**
 * Arduino NIO
 * 
 * ExternalEepromByteBuffer.cpp
 */

#ifndef __ARDUINO_NIO_EXTERNAL_EEPROM_BYTE_BUFFER_CPP__
#define __ARDUINO_NIO_EXTERNAL_EEPROM_BYTE_BUFFER_CPP__ 1

#include "ExternalEepromByteBuffer.h"

ExternalEepromByteBuffer::ExternalEepromByteBuffer(ExternalEeprom* externalEeprom) : ByteBuffer(0, 0, externalEeprom->getDeviceSize(), externalEeprom->getDeviceSize()), externalEeprom(externalEeprom) {
}

unsigned char ExternalEepromByteBuffer::get() {
    if (pos < lim) {
        return externalEeprom->read(pos++);
    }
    return 0;
}

void ExternalEepromByteBuffer::put(unsigned char b) {
    if (pos < lim) {
        externalEeprom->write(pos++, b);
    }
}

unsigned char ExternalEepromByteBuffer::get(unsigned int index) {
    if (index < lim) {
        return externalEeprom->read(index);
    }
    return 0;
}

void ExternalEepromByteBuffer::put(unsigned int index, unsigned char b) {
    if (index < lim) {
        externalEeprom->write(index, b);
    }
}

bool ExternalEepromByteBuffer::isReadOnly() {
    return false;
}

bool ExternalEepromByteBuffer::hasArray() {
    return false;
}

unsigned char* ExternalEepromByteBuffer::getArray() {
    return (unsigned char*) 0;
}

#endif /* __ARDUINO_NIO_EXTERNAL_EEPROM_BYTE_BUFFER_CPP__ */
