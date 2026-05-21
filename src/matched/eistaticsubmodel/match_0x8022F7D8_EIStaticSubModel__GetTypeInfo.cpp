// 0x8022F7D8 EIStaticSubModel::GetTypeInfo(void) const (12B)
struct EIStaticSubModelTypeInfo;
extern char s_EIStaticSubModel_typeInfo[];
class EIStaticSubModel { public: EIStaticSubModelTypeInfo* GetTypeInfo() const; };
EIStaticSubModelTypeInfo* EIStaticSubModel::GetTypeInfo() const {
    return (EIStaticSubModelTypeInfo*)s_EIStaticSubModel_typeInfo;
}
