/**
 * Arduino NIO
 * 
 * ResourceByteBuffer.h
 */

#ifndef __ARDUINO_NIO_RESOURCE_BYTE_BUFFER_H__
#define __ARDUINO_NIO_RESOURCE_BYTE_BUFFER_H__ 1

#include <ByteBuffer.h>
#include <Resource.h>

class ResourceByteBuffer : public ByteBuffer {
protected:

    Resource* resource;

public:

    ResourceByteBuffer(Resource* resource, unsigned int len);

    virtual unsigned char get();

    virtual void put(unsigned char b);

    virtual unsigned char get(unsigned int index);

    virtual void put(unsigned int index, unsigned char b);

    virtual bool isReadOnly();

    virtual bool hasArray();

    virtual unsigned char* getArray();
};

#endif /* __ARDUINO_NIO_RESOURCE_BYTE_BUFFER_H__ */
