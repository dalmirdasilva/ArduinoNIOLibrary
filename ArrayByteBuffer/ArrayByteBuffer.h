/**
 * Arduino NIO
 * 
 * ArrayByteBuffer.h
 */

#ifndef __ARDUINO_NIO_ARRAY_BYTE_BUFFER_H__
#define __ARDUINO_NIO_ARRAY_BYTE_BUFFER_H__ 1

#include <ByteBuffer.h>

class ArrayByteBuffer : public ByteBuffer {
protected:

    unsigned char* buf;

public:

    ArrayByteBuffer(unsigned char* buf, unsigned int len);

    virtual unsigned char get();

    virtual void put(unsigned char b);

    virtual unsigned char get(unsigned int index);

    virtual void put(unsigned int index, unsigned char b);

    virtual bool isReadOnly();

    virtual bool hasArray();

    virtual unsigned char* getArray();
};

#endif /* __ARDUINO_NIO_ARRAY_BYTE_BUFFER_H__ */
