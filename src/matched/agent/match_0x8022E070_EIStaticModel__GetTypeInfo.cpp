// 0x8022E070 (12B) EIStaticModel::GetTypeInfo(void) const
// Return pointer to global TypeInfo at 0x804FB400.

struct EIStaticModelTypeInfo;
extern char s_EIStaticModel_typeInfo[];

class EIStaticModel {
public:
    EIStaticModelTypeInfo* GetTypeInfo() const;
};

EIStaticModelTypeInfo* EIStaticModel::GetTypeInfo() const {
    return (EIStaticModelTypeInfo*)s_EIStaticModel_typeInfo;
}
