/* ISimsWallObjectModel::GetTypeName(void) const - 0x80053F64 (12 bytes) */
// TU: iobject

extern char ISimsWallObjectModel_typeInfo_name;

struct ISimsWallObjectModel {
    const char* GetTypeName() const;
};

const char* ISimsWallObjectModel::GetTypeName() const {
    return &ISimsWallObjectModel_typeInfo_name;
}
