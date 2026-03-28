/* ECheatLookup::ECheatLookup(void) at 0x800210E4 (64B) */

extern int __vt_ECheatLookup[];

struct ECheatLookup {
    char pad_00[0x04];
    int m_field04;
    char m_field08;
    char pad_09[0x3F];
    int* m_vtable;
    int m_field4C;
    int m_field50;
    int m_field54;
    int m_field58;
    int m_field5C;

    ECheatLookup();
};

ECheatLookup::ECheatLookup() {
    m_field04 = -1;
    m_field08 = 0;
    m_field4C = 2;
    m_field5C = 0;
    m_vtable = __vt_ECheatLookup;
    m_field50 = 0;
    m_field54 = 0;
    m_field58 = 0;
}
