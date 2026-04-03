// 0x80053F94 (12 bytes)
class ISimsWallObjectModel {
public:
    short GetReadVersion() const;
};

extern char gISimsWallObjectModelData[];

short ISimsWallObjectModel::GetReadVersion() const {
    return *(short*)(gISimsWallObjectModelData + 0);
}
