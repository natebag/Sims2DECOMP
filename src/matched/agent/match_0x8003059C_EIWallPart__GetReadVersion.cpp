/* EIWallPart::GetReadVersion(void) - 0x8003059C (12 bytes) */

struct TypeInfo {
    char pad[0x16];
    unsigned short m_readVersion;
};

extern TypeInfo EIWallPart_typeInfo;

struct EIWallPart {
    static unsigned short GetReadVersion();
};

unsigned short EIWallPart::GetReadVersion() {
    return EIWallPart_typeInfo.m_readVersion;
}
