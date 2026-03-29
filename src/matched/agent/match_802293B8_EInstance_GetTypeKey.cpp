// 0x802293B8 (12 bytes) - EInstance::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr

struct ETypeInfo_GTK { int data[5]; };
extern ETypeInfo_GTK EInstance_typeInfo_key;

struct EInstance_GTK {
    int GetTypeKey() const;
};

int EInstance_GTK::GetTypeKey() const {
    return EInstance_typeInfo_key.data[4];
}
