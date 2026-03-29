// 0x80053D1C (12 bytes)
class ISimsObjectModel {
public:
    short GetReadVersion() const;
};

extern char gISimsObjectModelData[];

short ISimsObjectModel::GetReadVersion() const {
    return *(short*)(gISimsObjectModelData + 0);
}
