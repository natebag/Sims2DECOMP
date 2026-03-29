/* ISimsObjectModel::GetTypeName(void) const - 0x80053CEC (12 bytes) */
// TU: iobject

extern char ISimsObjectModel_typeInfo_name;

struct ISimsObjectModel {
    const char* GetTypeName() const;
};

const char* ISimsObjectModel::GetTypeName() const {
    return &ISimsObjectModel_typeInfo_name;
}
