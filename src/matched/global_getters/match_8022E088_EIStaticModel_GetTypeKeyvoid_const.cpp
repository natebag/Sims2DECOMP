// 0x8022E088 (12 bytes)
class EIStaticModel {
public:
    const char* GetTypeKey() const;
};

extern char gEIStaticModelData[];

const char* EIStaticModel::GetTypeKey() const {
    return *(const char**)(gEIStaticModelData + 0);
}
