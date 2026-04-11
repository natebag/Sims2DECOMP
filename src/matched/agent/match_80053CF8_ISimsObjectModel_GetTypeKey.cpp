/* ISimsObjectModel::GetTypeKey(void) const - 0x80053CF8 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsObjectModel_typeInfo;

struct ISimsObjectModel {
    const char* GetTypeKey() const;
};

const char* ISimsObjectModel::GetTypeKey() const {
    return *(const char**)((char*)&ISimsObjectModel_typeInfo + 16);
}
