#ifndef STRINGBUFFER_H
#define STRINGBUFFER_H

#include "types.h"

// StringBuffer - Simple char buffer wrapper
// From: stringbuffer.obj
// Layout: { char* m_buffer; u32 m_capacity; }
class StringBuffer {
public:
    StringBuffer(char* buffer, unsigned int capacity);

    void erase(void);
    unsigned int capacity(void) const;
    unsigned int length(void) const;
    const char* c_str(void) const;
    char* buffer(void);

    void copy(char* src);
    void copy(StringBuffer& src);

    // Append operations (not small, declared for use by small functions)
    void append(char* str, int maxLen);
    void append(StringBuffer& src, int maxLen);

    void appendChar(char c);

private:
    char* m_buffer;        // offset 0x00
    unsigned int m_capacity; // offset 0x04
};

// File-static helper to convert wide string to ASCII
// (appears in both stringbuffer.obj and ctgdump.obj as separate copies)
static void localConvertToASCII(char* dst, unsigned short* src);

#endif // STRINGBUFFER_H
