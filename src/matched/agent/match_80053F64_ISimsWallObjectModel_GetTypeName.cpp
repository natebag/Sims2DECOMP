/* ISimsWallObjectModel::GetTypeName(void) const - 0x80053F64 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsWallObjectModel_typeInfo;

struct ISimsWallObjectModel {
    const char* GetTypeName() const;
};

const char* ISimsWallObjectModel::GetTypeName() const {
    return *(const char**)((char*)&ISimsWallObjectModel_typeInfo + 12);
}
