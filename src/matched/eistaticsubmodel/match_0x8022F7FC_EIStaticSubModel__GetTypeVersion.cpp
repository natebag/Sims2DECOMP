// 0x8022F7FC EIStaticSubModel::GetTypeVersion(void) const (12B)
struct EISMTypeInfo { char pad[12]; int name; int key; unsigned short version; unsigned short readVersion; };
extern char s_EIStaticSubModel_typeInfo[];
class EIStaticSubModel { public: unsigned short GetTypeVersion() const; };
unsigned short EIStaticSubModel::GetTypeVersion() const {
    return ((EISMTypeInfo*)s_EIStaticSubModel_typeInfo)->version;
}
