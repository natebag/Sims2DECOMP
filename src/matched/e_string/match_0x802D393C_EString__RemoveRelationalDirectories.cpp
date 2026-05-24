/* EString::RemoveRelationalDirectories(void) @ 0x802D393C (68 bytes) */
/* Canonical class layout from include/types/EString.h */
/* Header note: returns EString* (r3 preservation pattern). */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString& operator=(char* str);
    EString* RemoveRelationalDirectories(void);
};

char EString::m_null;

extern char* EPathUtil_RemoveRelationalDirectories(char* dst, char* src);

EString* EString::RemoveRelationalDirectories(void) {
    char buf[264];
    char* result = EPathUtil_RemoveRelationalDirectories(buf, m_buffer);
    operator=(result);
    return this;
}
