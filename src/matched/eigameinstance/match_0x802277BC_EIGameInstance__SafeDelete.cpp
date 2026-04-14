// 0x802277BC EIGameInstance::SafeDelete (64B)

struct EIGameInstance {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIGameInstance();
    void SafeDelete();
};

void EIGameInstance::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
