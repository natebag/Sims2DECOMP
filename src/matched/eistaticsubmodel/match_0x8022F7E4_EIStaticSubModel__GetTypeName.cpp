// 0x8022F7E4 EIStaticSubModel::GetTypeName(void) const (12B)
struct EISMTypeInfo { char pad[12]; int name; int key; short version; short readVersion; };
extern char s_EIStaticSubModel_typeInfo[];
class EIStaticSubModel { public: int GetTypeName() const; };
int EIStaticSubModel::GetTypeName() const {
    return ((EISMTypeInfo*)s_EIStaticSubModel_typeInfo)->name;
}
