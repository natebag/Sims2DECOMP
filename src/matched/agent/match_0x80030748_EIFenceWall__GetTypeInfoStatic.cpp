/* EIFenceWall::GetTypeInfoStatic(void) - 0x80030748 (12 bytes) */

struct TypeInfo;

extern TypeInfo EIFenceWall_typeInfo;

struct EIFenceWall {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIFenceWall::GetTypeInfoStatic() {
    return &EIFenceWall_typeInfo;
}
