/**
 * Arduino NIO
 * 
 * ExternalEepromByteBuffer.h
 */

#ifndef __ARDUINO_NIO_EXTERNAL_EEPROM_BYTE_BUFFER_H__
#define __ARDUINO_NIO_EXTERNAL_EEPROM_BYTE_BUFFER_H__ 1

#include <ByteBuffer.h>
#include <ExternalEeprom.h>

class ExternalEepromByteBuffer : public ByteBuffer {
protected:

    ExternalEeprom* externalEeprom;

public:

    ExternalEepromByteBuffer(ExternalEeprom* externalEeprom);

    virtual unsigned char get();

    virtual void put(unsigned char b);

    virtual unsigned char get(unsigned int index);

    virtual void put(unsigned int index, unsigned char b);

    virtual bool isReadOnly();

    virtual bool hasArray();

    virtual unsigned char* getArray();
};

#endif /* __ARDUINO_NIO_EXTERNAL_EEPROM_BYTE_BUFFER_H__ */
