// match_803C1444_EStorable_GetTypeVersion.cpp
// Address: 0x803C1444 | Size: 12 bytes
// Symbol: EStorable::GetTypeVersion(void) const
// Pattern C: lis r9 + lhz r3 → return unsigned short from global (offset +20, index 5)

struct ETypeInfo_EStorable_GTV { int data[6]; };
extern ETypeInfo_EStorable_GTV lbl_EStorable_TypeInfo_Version;

struct EStorable_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short EStorable_GTV::GetTypeVersion() const {
    return *(unsigned short*)&lbl_EStorable_TypeInfo_Version.data[5];
}
