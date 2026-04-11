/* ISimsObjectModel::GetReadVersion(void) const - 0x80053D1C (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsObjectModel_typeInfo;

struct ISimsObjectModel {
    short GetReadVersion() const;
};

short ISimsObjectModel::GetReadVersion() const {
    return *(short*)((char*)&ISimsObjectModel_typeInfo + 22);
}
