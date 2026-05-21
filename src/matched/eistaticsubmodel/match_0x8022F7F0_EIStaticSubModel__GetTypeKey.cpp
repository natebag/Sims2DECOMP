// 0x8022F7F0 EIStaticSubModel::GetTypeKey(void) const (12B)
struct EISMTypeInfo { char pad[12]; int name; int key; short version; short readVersion; };
extern char s_EIStaticSubModel_typeInfo[];
class EIStaticSubModel { public: int GetTypeKey() const; };
int EIStaticSubModel::GetTypeKey() const {
    return ((EISMTypeInfo*)s_EIStaticSubModel_typeInfo)->key;
}
