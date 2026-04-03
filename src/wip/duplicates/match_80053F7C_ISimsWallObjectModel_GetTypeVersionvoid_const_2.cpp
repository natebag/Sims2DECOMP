// 0x80053F7C (12 bytes)
class ISimsWallObjectModel {
public:
    short GetTypeVersion() const;
};

extern char gISimsWallObjectModelData[];

short ISimsWallObjectModel::GetTypeVersion() const {
    return *(short*)(gISimsWallObjectModelData + 0);
}
