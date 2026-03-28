/* EIFenceWall::GetTypeInfo(void) const - 0x80030718 (12 bytes) */

struct TypeInfo;

extern TypeInfo EIFenceWall_typeInfo;

struct EIFenceWall {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIFenceWall::GetTypeInfo() const {
    return &EIFenceWall_typeInfo;
}
