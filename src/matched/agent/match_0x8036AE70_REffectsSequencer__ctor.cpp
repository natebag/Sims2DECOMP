// 0x8036AE70 REffectsSequencer::REffectsSequencer(void) (60 B)

extern char s_REffectsSequencer_vtable[];

class EResource {
public:
    EResource();
};

class REffectsSequencer : public EResource {
public:
    REffectsSequencer();
};

REffectsSequencer::REffectsSequencer() : EResource() {
    *(void**)this = s_REffectsSequencer_vtable;
}
