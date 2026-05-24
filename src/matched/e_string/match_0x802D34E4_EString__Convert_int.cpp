/* EString::Convert(int) @ 0x802D34E4 (80 bytes) */
/* Canonical class layout from include/types/EString.h */
/* Uses 40-byte stack buffer for Sprintf result. */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString& operator=(char* str);
    EString* Convert(int val);
};

char EString::m_null;

extern int Sprintf(char* buf, const char* fmt, ...);

EString* EString::Convert(int val) {
    char buf[40];
    Sprintf(buf, "%d", val);
    operator=(buf);
    return this;
}
