/* ISimsWallObjectModel::GetTypeKey(void) const - 0x80053F70 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsWallObjectModel_typeInfo;

struct ISimsWallObjectModel {
    const char* GetTypeKey() const;
};

const char* ISimsWallObjectModel::GetTypeKey() const {
    return *(const char**)((char*)&ISimsWallObjectModel_typeInfo + 16);
}
