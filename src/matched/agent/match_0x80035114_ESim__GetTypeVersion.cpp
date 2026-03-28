/* ESim::GetTypeVersion(void) const - 0x80035114 (12 bytes) */

struct TypeInfo {
    char pad[0x14];
    unsigned short m_version;
};

extern TypeInfo ESim_typeInfo;

struct ESim {
    unsigned short GetTypeVersion() const;
};

unsigned short ESim::GetTypeVersion() const {
    return ESim_typeInfo.m_version;
}
