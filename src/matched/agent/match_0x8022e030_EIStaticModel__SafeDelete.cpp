// 0x8022E030 EIStaticModel::SafeDelete(void) (64B)
struct EIStaticModel {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual ~EIStaticModel();
    void SafeDelete();
};
void EIStaticModel::SafeDelete() { if (this != 0) { delete this; } }
