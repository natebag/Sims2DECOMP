// match_803C1438_EStorable_GetTypeKey.cpp
// Address: 0x803C1438 | Size: 12 bytes
// Symbol: EStorable::GetTypeKey(void) const
// Pattern B: lis r9 + lwz r3 → return word from global (offset +16, index 4)

struct ETypeInfo_EStorable_GTK { int data[5]; };
extern ETypeInfo_EStorable_GTK lbl_EStorable_TypeInfo_Key;

struct EStorable_GTK {
    int GetTypeKey() const;
};

int EStorable_GTK::GetTypeKey() const {
    return lbl_EStorable_TypeInfo_Key.data[4];
}
