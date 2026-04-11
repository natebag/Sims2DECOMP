/* ISimsWallObjectModel::GetReadVersion(void) const - 0x80053F94 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsWallObjectModel_typeInfo;

struct ISimsWallObjectModel {
    short GetReadVersion() const;
};

short ISimsWallObjectModel::GetReadVersion() const {
    return *(short*)((char*)&ISimsWallObjectModel_typeInfo + 22);
}
