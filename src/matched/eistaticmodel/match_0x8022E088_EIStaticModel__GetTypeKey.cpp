// 0x8022E088 (12B) EIStaticModel::GetTypeKey(void) const
// Load global TypeInfo.key at offset 16.

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
    int GetTypeKey() const;
};

int EIStaticModel::GetTypeKey() const {
    return ((EIStaticModelTypeInfo*)s_EIStaticModel_typeInfo)->key;
}
