/* ESim::GetReadVersion(void) - 0x8003512C (12 bytes) */

struct TypeInfo {
    char pad[0x16];
    unsigned short m_readVersion;
};

extern TypeInfo ESim_typeInfo;

struct ESim {
    static unsigned short GetReadVersion();
};

unsigned short ESim::GetReadVersion() {
    return ESim_typeInfo.m_readVersion;
}
