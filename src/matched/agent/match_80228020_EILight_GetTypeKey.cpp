// match_80228020_EILight_GetTypeKey.cpp
// Address: 0x80228020 | Size: 12 bytes
// Symbol: EILight::GetTypeKey(void) const
// Pattern B: lis r9 + lwz r3 → return word from global (offset +16, index 4)

struct ETypeInfo_EILight_GTK { int data[5]; };
extern ETypeInfo_EILight_GTK lbl_EILight_TypeInfo_Key;

struct EILight_GTK {
    int GetTypeKey() const;
};

int EILight_GTK::GetTypeKey() const {
    return lbl_EILight_TypeInfo_Key.data[4];
}
