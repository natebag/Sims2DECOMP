// match_80228014_EILight_GetTypeName.cpp
// Address: 0x80228014 | Size: 12 bytes
// Symbol: EILight::GetTypeName(void) const
// Pattern B: lis r9 + lwz r3 → return word from global (offset +12, index 3)

struct ETypeInfo_EILight_GTN { int data[4]; };
extern ETypeInfo_EILight_GTN lbl_EILight_TypeInfo_Name;

struct EILight_GTN {
    int GetTypeName() const;
};

int EILight_GTN::GetTypeName() const {
    return lbl_EILight_TypeInfo_Name.data[3];
}
