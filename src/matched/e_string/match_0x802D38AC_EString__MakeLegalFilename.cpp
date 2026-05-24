/* EString::MakeLegalFilename(void) @ 0x802D38AC (56 bytes) */
/* NOTE: canonical header declares void, but DOL requires EString* return (r3 preservation) */

class EString {
public:
    char* m_buffer;
    EString* MakeLegalFilename(void);
};

extern "C" void EPathUtil__MakeLegalFilename_char_ptr__char_ptr(char* dst, char* src);

EString* EString::MakeLegalFilename(void) {
    EPathUtil__MakeLegalFilename_char_ptr__char_ptr(m_buffer, m_buffer);
    return this;
}
