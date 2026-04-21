// 0x8022E0AC (12B) EIStaticModel::GetReadVersion(void)
// Load global TypeInfo.readVersion (short) at offset 22.

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
    unsigned short GetReadVersion();
};

unsigned short EIStaticModel::GetReadVersion() {
    return ((EIStaticModelTypeInfo*)s_EIStaticModel_typeInfo)->readVersion;
}
