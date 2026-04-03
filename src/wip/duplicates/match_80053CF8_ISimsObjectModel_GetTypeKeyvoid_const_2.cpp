// 0x80053CF8 (12 bytes)
class ISimsObjectModel {
public:
    const char* GetTypeKey() const;
};

extern char gISimsObjectModelData[];

const char* ISimsObjectModel::GetTypeKey() const {
    return *(const char**)(gISimsObjectModelData + 0);
}
