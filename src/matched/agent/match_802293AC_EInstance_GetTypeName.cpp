// 0x802293AC (12 bytes) - EInstance::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr
// Loads a word (name pointer) from the global ETypeInfo

struct ETypeInfo_GTN { int data[4]; };
extern ETypeInfo_GTN EInstance_typeInfo_name;

struct EInstance_GTN {
    int GetTypeName() const;
};

int EInstance_GTN::GetTypeName() const {
    return EInstance_typeInfo_name.data[3];
}
