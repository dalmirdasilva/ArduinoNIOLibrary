/**
 * Arduino NIO
 * 
 * Buffer.h
 */

#ifndef __ARDUINO_NIO_BUFFER_H__
#define __ARDUINO_NIO_BUFFER_H__ 1

class Buffer {
    
protected:

    bool marked;
    unsigned int markpos;
    unsigned int pos;
    unsigned int lim;
    unsigned int cap;

    Buffer(unsigned int mark, unsigned int pos, unsigned int lim, unsigned int cap);

public:
    
    unsigned int getCapacity();

    unsigned int getPosition();

    void setPosition(unsigned int pos);

    unsigned int getLimit();

    void setLimit(unsigned int lim);

    void mark();

    void reset();

    void clear();

    void flip();

    void rewind();

    unsigned int getRemaining();

    bool hasRemaining();

    virtual bool isReadOnly() = 0;

    virtual bool hasArray() = 0;

    virtual unsigned char* getArray() = 0;
};

#endif /* __ARDUINO_NIO_BUFFER_H__ */
