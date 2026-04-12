// 0x8022E094 (12 bytes)
class EIStaticModel {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEIStaticModelData[];

unsigned short EIStaticModel::GetTypeVersion() const {
    return gEIStaticModelData[0];
}
