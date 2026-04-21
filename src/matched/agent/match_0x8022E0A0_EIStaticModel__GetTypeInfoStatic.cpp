// 0x8022E0A0 (12B) EIStaticModel::GetTypeInfoStatic(void)
// Return pointer to global TypeInfo — static twin of GetTypeInfo.

struct EIStaticModelTypeInfo;
extern char s_EIStaticModel_typeInfo[];

class EIStaticModel {
public:
    static EIStaticModelTypeInfo* GetTypeInfoStatic();
};

EIStaticModelTypeInfo* EIStaticModel::GetTypeInfoStatic() {
    return (EIStaticModelTypeInfo*)s_EIStaticModel_typeInfo;
}
