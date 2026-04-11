/* ISimsWallObjectModel::GetTypeVersion(void) const - 0x80053F7C (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsWallObjectModel_typeInfo;

struct ISimsWallObjectModel {
    short GetTypeVersion() const;
};

short ISimsWallObjectModel::GetTypeVersion() const {
    return *(short*)((char*)&ISimsWallObjectModel_typeInfo + 20);
}
