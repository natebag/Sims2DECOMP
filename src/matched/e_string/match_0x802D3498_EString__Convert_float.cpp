/* EString::Convert(float) @ 0x802D3498 (76 bytes) */
/* Canonical class layout from include/types/EString.h */
/* Uses 40-byte stack buffer for Sprintf result. */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString& operator=(char* str);
    EString* Convert(float val);
};

char EString::m_null;

extern int Sprintf(char* buf, const char* fmt, ...);

EString* EString::Convert(float val) {
    char buf[40];
    Sprintf(buf, "%g", val);
    operator=(buf);
    return this;
}
