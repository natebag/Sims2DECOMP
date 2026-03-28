typedef unsigned int size_t;
extern "C" void* memset(void*, int, size_t);

class INVTarget {
public:
    char pad[0x18B];
    char m_cheatStrings[5][0x800];
    void ClearAllCheatStrings(void);
};

void INVTarget::ClearAllCheatStrings(void) {
    int i;
    for (i = 0; i < 5; i++) {
        memset(m_cheatStrings[i], 0, 0x800);
    }
}
