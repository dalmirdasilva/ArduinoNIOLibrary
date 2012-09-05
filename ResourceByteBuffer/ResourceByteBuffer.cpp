/**
 * Arduino NIO
 * 
 * ResourceByteBuffer.cpp
 */

#ifndef __ARDUINO_NIO_RESOURCE_BYTE_BUFFER_CPP__
#define __ARDUINO_NIO_RESOURCE_BYTE_BUFFER_CPP__ 1

#include "ResourceByteBuffer.h"

ResourceByteBuffer::ResourceByteBuffer(Resource* resource, unsigned int len) : ByteBuffer(0, 0, len, len), resource(resource) {
    if (resource->size() < len) {
        unsigned int needed = len - resource->size();  
        resource->seek(Resource::SEEK_ORIGIN_BEGIN, resource->size());
        for (unsigned int i = 0; i < needed; i++) {
            resource->write(0x00);
        }
    }
}

unsigned char ResourceByteBuffer::get() {
    if (pos < lim) {
        pos++;
        return resource->read();
    }
    return 0;
}

void ResourceByteBuffer::put(unsigned char b) {
    if (pos < lim) {
        pos++;
        resource->write(b);
    }
}

unsigned char ResourceByteBuffer::get(unsigned int index) {
    if (index < lim) {
        unsigned char b = 0;
        resource->seek(Resource::SEEK_ORIGIN_BEGIN, index);
        b = resource->read();
        resource->seek(Resource::SEEK_ORIGIN_BEGIN, pos);
        return b;
    }
    return 0;
}

void ResourceByteBuffer::put(unsigned int index, unsigned char b) {
    if (index < lim) {
        resource->seek(Resource::SEEK_ORIGIN_BEGIN, index);
        resource->write(b);
        resource->seek(Resource::SEEK_ORIGIN_BEGIN, pos);
    }
}

bool ResourceByteBuffer::isReadOnly() {
    return resource->isReadOnly();
}

bool ResourceByteBuffer::hasArray() {
    return false;
}

unsigned char* ResourceByteBuffer::getArray() {
    return (unsigned char *) 0;
}

#endif /* __ARDUINO_NIO_RESOURCE_BYTE_BUFFER_CPP__ */

