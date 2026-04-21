// 0x8022E07C (12B) EIStaticModel::GetTypeName(void) const
// Load global TypeInfo.name at offset 12.

struct EIStaticModelTypeInfo {
    char pad[12];
    int name;
    int key;
    short version;
    short readVersion;
};

extern char s_EIStaticModel_typeInfo[];

class EIStaticModel {
public:
    int GetTypeName() const;
};

int EIStaticModel::GetTypeName() const {
    return ((EIStaticModelTypeInfo*)s_EIStaticModel_typeInfo)->name;
}
