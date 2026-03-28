#ifndef CTGDUMP_H
#define CTGDUMP_H

#include "types.h"

// CTGDump - Debug dump/logging class
// From: ctgdump.obj
// All output operations are no-ops in release builds
class CTGDump {
public:
    CTGDump(void);
    ~CTGDump(void);

    void Shutdown(void);

    // Stream operators - all no-ops in release
    CTGDump& operator<<(char* str);
    CTGDump& operator<<(unsigned short* wstr);
    CTGDump& operator<<(double& val);
    CTGDump& operator<<(int val);
    CTGDump& operator<<(unsigned int val);
    CTGDump& operator<<(char val);
    CTGDump& operator<<(unsigned long val);
};

#endif // CTGDUMP_H
