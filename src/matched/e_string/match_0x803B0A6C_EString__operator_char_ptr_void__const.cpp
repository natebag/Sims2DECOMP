/* EString::operator char*(void) const @ 0x803B0A6C (8 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    operator char*(void) const;
};

EString::operator char*(void) const {
    return m_buffer;
}
