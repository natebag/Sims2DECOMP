// 0x80053CEC (12 bytes)
class ISimsObjectModel {
public:
    const char* GetTypeName() const;
};

extern char gISimsObjectModelData[];

const char* ISimsObjectModel::GetTypeName() const {
    return *(const char**)(gISimsObjectModelData + 0);
}
