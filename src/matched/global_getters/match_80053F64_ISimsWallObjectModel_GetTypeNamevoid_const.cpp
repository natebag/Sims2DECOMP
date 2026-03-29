// 0x80053F64 (12 bytes)
class ISimsWallObjectModel {
public:
    const char* GetTypeName() const;
};

extern char gISimsWallObjectModelData[];

const char* ISimsWallObjectModel::GetTypeName() const {
    return *(const char**)(gISimsWallObjectModelData + 0);
}
