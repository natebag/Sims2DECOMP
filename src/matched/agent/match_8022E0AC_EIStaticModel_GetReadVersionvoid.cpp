// 0x8022E0AC (12 bytes)
class EIStaticModel {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gEIStaticModelData[];

unsigned short EIStaticModel::GetReadVersion() const {
    return gEIStaticModelData[1];
}
