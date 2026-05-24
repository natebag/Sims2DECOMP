/* EFixedString::Convert(double) @ 0x802C8630 (36 bytes) */
/* Canonical class layout from include/types/EString.h */

class EFixedString {
public:
    char* m_buffer;
    int m_maxLen;
    void Convert(float val);
    void Convert(double val);
};

void EFixedString::Convert(double val) {
    Convert((float)val);
}
