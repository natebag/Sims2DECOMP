// match_803C142C_EStorable_GetTypeName.cpp
// Address: 0x803C142C | Size: 12 bytes
// Symbol: EStorable::GetTypeName(void) const
// Pattern B: lis r9 + lwz r3 → return word from global (offset +12, index 3)

struct ETypeInfo_EStorable_GTN { int data[4]; };
extern ETypeInfo_EStorable_GTN lbl_EStorable_TypeInfo_Name;

struct EStorable_GTN {
    int GetTypeName() const;
};

int EStorable_GTN::GetTypeName() const {
    return lbl_EStorable_TypeInfo_Name.data[3];
}
