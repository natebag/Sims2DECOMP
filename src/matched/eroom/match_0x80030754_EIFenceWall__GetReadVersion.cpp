/* EIFenceWall::GetReadVersion(void) - 0x80030754 (12 bytes) */

struct TypeInfo {
    char pad[0x16];
    unsigned short m_readVersion;
};

extern TypeInfo EIFenceWall_typeInfo;

struct EIFenceWall {
    static unsigned short GetReadVersion();
};

unsigned short EIFenceWall::GetReadVersion() {
    return EIFenceWall_typeInfo.m_readVersion;
}
