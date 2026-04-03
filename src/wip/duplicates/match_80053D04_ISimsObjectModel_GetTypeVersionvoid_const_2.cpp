// 0x80053D04 (12 bytes)
class ISimsObjectModel {
public:
    short GetTypeVersion() const;
};

extern char gISimsObjectModelData[];

short ISimsObjectModel::GetTypeVersion() const {
    return *(short*)(gISimsObjectModelData + 0);
}
