/* EString::MakeLower(void) @ 0x802D2C7C (52 bytes) */
/* Canonical class layout from include/types/EString.h */
/* Header bug: canonical header declares void MakeLower(void) but byte-match */
/* requires EString* return (r3 preservation, same pattern as MakeUpper). */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString* MakeLower(void);
};

extern "C" char* strlwr(char* s);

EString* EString::MakeLower(void) {
    strlwr(m_buffer);
    return this;
}
