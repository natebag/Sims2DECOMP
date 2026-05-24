/* EString::Trim(char*) @ 0x802D3C08 (64 bytes) */
/* Canonical class layout from include/types/EString.h */
/* Header note: Trim/TrimLeft/TrimRight likely need EString* return per */
/* mutator r3-preservation pattern. */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString* TrimLeft(char* chars);
    EString* TrimRight(char* chars);
    EString* Trim(char* chars);
};

char EString::m_null;

EString* EString::Trim(char* chars) {
    TrimLeft(chars);
    TrimRight(chars);
    return this;
}
