/* ISimsObjectModel::GetTypeInfoStatic(void) - 0x80053D10 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsObjectModel_typeInfo;

struct ISimsObjectModel {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ISimsObjectModel::GetTypeInfoStatic() {
    return &ISimsObjectModel_typeInfo;
}
