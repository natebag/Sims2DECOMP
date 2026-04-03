// 0x8021F164 (52 bytes) - InteractorModule::SocialModeInteractor::~SocialModeInteractor(void)
// vtable at offset +0x5C, stores base class vtable then conditional delete

struct NonVirtualBase_SMI {
    char data[0x5C];
};

struct SMI_dtor : NonVirtualBase_SMI {
    virtual ~SMI_dtor();
};

SMI_dtor::~SMI_dtor() {}
