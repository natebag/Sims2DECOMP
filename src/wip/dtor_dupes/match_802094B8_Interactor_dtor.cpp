// 0x802094B8 (52 bytes) - InteractorModule::Interactor::~Interactor(void)
// Same pattern as SocialModeInteractor dtor: vtable at +0x5C

struct NonVirtualBase_ID {
    char data[0x5C];
};

struct Interactor_dtor : NonVirtualBase_ID {
    virtual ~Interactor_dtor();
};

Interactor_dtor::~Interactor_dtor() {}
