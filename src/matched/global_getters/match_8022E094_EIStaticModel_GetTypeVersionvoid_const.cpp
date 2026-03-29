// 0x8022E094 (12 bytes)
class EIStaticModel {
public:
    short GetTypeVersion() const;
};

extern char gEIStaticModelData[];

short EIStaticModel::GetTypeVersion() const {
    return *(short*)(gEIStaticModelData + 0);
}
