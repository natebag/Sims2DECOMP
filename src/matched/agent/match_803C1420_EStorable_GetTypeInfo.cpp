// match_803C1420_EStorable_GetTypeInfo.cpp
// Address: 0x803C1420 | Size: 12 bytes
// Symbol: EStorable::GetTypeInfo(void) const
// Pattern A: lis r3 + addi r3 → return address of global struct

struct ETypeInfo_EStorable_GTI { int data[4]; };
extern ETypeInfo_EStorable_GTI lbl_EStorable_TypeInfo;

struct EStorable {
    ETypeInfo_EStorable_GTI* GetTypeInfo() const;
};

ETypeInfo_EStorable_GTI* EStorable::GetTypeInfo() const {
    return &lbl_EStorable_TypeInfo;
}
