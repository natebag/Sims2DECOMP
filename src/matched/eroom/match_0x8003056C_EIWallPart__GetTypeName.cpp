/* EIWallPart::GetTypeName(void) const - 0x8003056C (12 bytes) */

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIWallPart_typeInfo;

struct EIWallPart {
    const char* GetTypeName() const;
};

const char* EIWallPart::GetTypeName() const {
    return EIWallPart_typeInfo.m_name;
}
