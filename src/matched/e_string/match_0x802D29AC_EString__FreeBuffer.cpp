/* EString::FreeBuffer(char*) @ 0x802D29AC (52 bytes) */
/* Canonical class layout from include/types/EString.h */

class EAHeap {
public:
    void Free(void* p);
};

class EString {
public:
    char* m_buffer;
    static char m_null;
    void FreeBuffer(char* buf);
};

char EString::m_null;

extern "C" EAHeap* MainHeap(void);

void EString::FreeBuffer(char* buf) {
    MainHeap()->Free(buf);
}
