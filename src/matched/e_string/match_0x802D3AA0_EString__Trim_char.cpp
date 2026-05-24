/* EString::Trim(char) @ 0x802D3AA0 (64 bytes) */
/* Canonical class layout from include/types/EString.h */
/* Header note: Trim/TrimLeft/TrimRight likely need EString* return per */
/* mutator r3-preservation pattern. */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString* TrimLeft(char c);
    EString* TrimRight(char c);
    EString* Trim(char c);
};

char EString::m_null;

EString* EString::Trim(char c) {
    TrimLeft(c);
    TrimRight(c);
    return this;
}
