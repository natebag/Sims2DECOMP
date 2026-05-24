/* EString::Convert(double) @ 0x802D3ED8 (36 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    void Convert(float val);
    void Convert(double val);
};

char EString::m_null;

void EString::Convert(double val) {
    Convert((float)val);
}
