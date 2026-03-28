/* EIWallPart::GetTypeInfo(void) const - 0x80030560 (12 bytes) */

struct TypeInfo;

extern TypeInfo EIWallPart_typeInfo;

struct EIWallPart {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIWallPart::GetTypeInfo() const {
    return &EIWallPart_typeInfo;
}
