// 0x80227674 EIGameInstance::EIGameInstance (60B)

struct EInstance {
    virtual ~EInstance();
    EInstance();
};

struct EIGameInstance : EInstance {
    EIGameInstance();
};

EIGameInstance::EIGameInstance() {
}
