// 0x8022E094 (12B) EIStaticModel::GetTypeVersion(void) const
// Load global TypeInfo.version (short) at offset 20.

struct EIStaticModelTypeInfo {
    char pad[12];
    int name;
    int key;
    unsigned short version;
    unsigned short readVersion;
};

extern char s_EIStaticModel_typeInfo[];

class EIStaticModel {
public:
    unsigned short GetTypeVersion() const;
};

unsigned short EIStaticModel::GetTypeVersion() const {
    return ((EIStaticModelTypeInfo*)s_EIStaticModel_typeInfo)->version;
}
