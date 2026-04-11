/* ISimsObjectModel::GetTypeName(void) const - 0x80053CEC (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsObjectModel_typeInfo;

struct ISimsObjectModel {
    const char* GetTypeName() const;
};

const char* ISimsObjectModel::GetTypeName() const {
    return *(const char**)((char*)&ISimsObjectModel_typeInfo + 12);
}
