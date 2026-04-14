/* EIWallPart::GetTypeKey(void) const - 0x80030578 (12 bytes) */

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIWallPart_typeInfo;

struct EIWallPart {
    unsigned int GetTypeKey() const;
};

unsigned int EIWallPart::GetTypeKey() const {
    return EIWallPart_typeInfo.m_key;
}
