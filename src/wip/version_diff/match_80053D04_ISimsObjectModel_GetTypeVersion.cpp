/* ISimsObjectModel::GetTypeVersion(void) const - 0x80053D04 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsObjectModel_typeInfo;

struct ISimsObjectModel {
    short GetTypeVersion() const;
};

short ISimsObjectModel::GetTypeVersion() const {
    return *(short*)((char*)&ISimsObjectModel_typeInfo + 20);
}
