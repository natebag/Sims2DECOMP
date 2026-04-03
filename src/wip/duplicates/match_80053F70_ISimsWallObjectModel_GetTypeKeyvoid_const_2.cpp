// 0x80053F70 (12 bytes)
class ISimsWallObjectModel {
public:
    const char* GetTypeKey() const;
};

extern char gISimsWallObjectModelData[];

const char* ISimsWallObjectModel::GetTypeKey() const {
    return *(const char**)(gISimsWallObjectModelData + 0);
}
