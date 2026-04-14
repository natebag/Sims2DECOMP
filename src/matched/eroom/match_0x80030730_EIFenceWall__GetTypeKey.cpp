/* EIFenceWall::GetTypeKey(void) const - 0x80030730 (12 bytes) */

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIFenceWall_typeInfo;

struct EIFenceWall {
    unsigned int GetTypeKey() const;
};

unsigned int EIFenceWall::GetTypeKey() const {
    return EIFenceWall_typeInfo.m_key;
}
