/* ESim::GetTypeKey(void) const - 0x80035108 (12 bytes) */

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo ESim_typeInfo;

struct ESim {
    unsigned int GetTypeKey() const;
};

unsigned int ESim::GetTypeKey() const {
    return ESim_typeInfo.m_key;
}
