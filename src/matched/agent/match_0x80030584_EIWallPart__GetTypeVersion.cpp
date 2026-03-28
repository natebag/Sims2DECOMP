/* EIWallPart::GetTypeVersion(void) const - 0x80030584 (12 bytes) */

struct TypeInfo {
    char pad[0x14];
    unsigned short m_version;
};

extern TypeInfo EIWallPart_typeInfo;

struct EIWallPart {
    unsigned short GetTypeVersion() const;
};

unsigned short EIWallPart::GetTypeVersion() const {
    return EIWallPart_typeInfo.m_version;
}
