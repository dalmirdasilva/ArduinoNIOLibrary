/**
 * Arduino NIO
 * 
 * ByteBuffer.h
 */

#ifndef __ARDUINO_NIO_BYTE_BUFFER_H__
#define __ARDUINO_NIO_BYTE_BUFFER_H__ 1

#include <Buffer.h>

class ByteBuffer : public Buffer {

protected:
    
    ByteBuffer(unsigned int mark, unsigned int pos, unsigned int lim, unsigned int cap);
    
public:

    virtual unsigned char get() = 0;

    virtual void put(unsigned char b) = 0;

    virtual unsigned char get(unsigned int index) = 0;

    virtual void put(unsigned int index, unsigned char b) = 0;

    virtual bool get(unsigned char* dst, int off, int len);

    bool get(unsigned char* dst, int len);

    virtual bool put(unsigned char* src, int off, int len);

    bool put(unsigned char* src, int len);

    virtual bool put(ByteBuffer* src);

    virtual bool put(ByteBuffer* src, int len);
};

#endif /* __ARDUINO_NIO_BYTE_BUFFER_H__ */

