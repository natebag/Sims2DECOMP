/* EIFenceWall::GetTypeName(void) const - 0x80030724 (12 bytes) */

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIFenceWall_typeInfo;

struct EIFenceWall {
    const char* GetTypeName() const;
};

const char* EIFenceWall::GetTypeName() const {
    return EIFenceWall_typeInfo.m_name;
}
