// 0x8022F798 EIStaticSubModel::SafeDelete(void) (64B)
struct EIStaticSubModel {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual ~EIStaticSubModel();
    void SafeDelete();
};
void EIStaticSubModel::SafeDelete() { if (this != 0) { delete this; } }
