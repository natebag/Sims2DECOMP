// 0x8022F814 EIStaticSubModel::GetReadVersion(void) (12B)
struct EISMTypeInfo { char pad[12]; int name; int key; unsigned short version; unsigned short readVersion; };
extern char s_EIStaticSubModel_typeInfo[];
class EIStaticSubModel { public: unsigned short GetReadVersion() const; };
unsigned short EIStaticSubModel::GetReadVersion() const {
    return ((EISMTypeInfo*)s_EIStaticSubModel_typeInfo)->readVersion;
}
