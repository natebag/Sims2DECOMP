// 0x8022E07C (12 bytes)
class EIStaticModel {
public:
    const char* GetTypeName() const;
};

extern char gEIStaticModelData[];

const char* EIStaticModel::GetTypeName() const {
    return *(const char**)(gEIStaticModelData + 0);
}
