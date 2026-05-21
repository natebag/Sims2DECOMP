// 0x8022F808 EIStaticSubModel::GetTypeInfoStatic(void) (12B)
struct EIStaticSubModelTypeInfo;
extern char s_EIStaticSubModel_typeInfo[];
EIStaticSubModelTypeInfo* EIStaticSubModel_GetTypeInfoStatic() {
    return (EIStaticSubModelTypeInfo*)s_EIStaticSubModel_typeInfo;
}
