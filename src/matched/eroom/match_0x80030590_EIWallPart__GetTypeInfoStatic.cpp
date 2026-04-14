/* EIWallPart::GetTypeInfoStatic(void) - 0x80030590 (12 bytes) */

struct TypeInfo;

extern TypeInfo EIWallPart_typeInfo;

struct EIWallPart {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIWallPart::GetTypeInfoStatic() {
    return &EIWallPart_typeInfo;
}
