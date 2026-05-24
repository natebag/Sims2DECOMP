/* EFixedString::ReleaseBuffer(void) @ 0x802C862C (4 bytes) */
/* Canonical class layout from include/types/EString.h */

class EFixedString {
public:
    char* m_buffer;
    int m_maxLen;
    void ReleaseBuffer(void);
};

void EFixedString::ReleaseBuffer(void) {
}
