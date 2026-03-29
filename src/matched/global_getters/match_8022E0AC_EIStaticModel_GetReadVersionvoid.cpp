// 0x8022E0AC (12 bytes)
class EIStaticModel {
public:
    short GetReadVersion() const;
};

extern char gEIStaticModelData[];

short EIStaticModel::GetReadVersion() const {
    return *(short*)(gEIStaticModelData + 0);
}
