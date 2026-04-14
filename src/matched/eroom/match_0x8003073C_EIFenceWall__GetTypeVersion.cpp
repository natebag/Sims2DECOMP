/* EIFenceWall::GetTypeVersion(void) const - 0x8003073C (12 bytes) */

struct TypeInfo {
    char pad[0x14];
    unsigned short m_version;
};

extern TypeInfo EIFenceWall_typeInfo;

struct EIFenceWall {
    unsigned short GetTypeVersion() const;
};

unsigned short EIFenceWall::GetTypeVersion() const {
    return EIFenceWall_typeInfo.m_version;
}
