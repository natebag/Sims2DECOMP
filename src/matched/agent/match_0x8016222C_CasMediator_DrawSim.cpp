// FLAGS: -msdata=eabi -G 8
// 0x8016222C CasMediator::DrawSim (64b)
struct DrawTarget {
    int pad;
    virtual void V0(); virtual void V1(); virtual void V2();
    virtual void V3(); virtual void V4(); virtual void V5();
    virtual void V6(); virtual void V7(); virtual void V8();
    virtual void V9(); virtual void V10(); virtual void V11();
};

struct CasMediator {
    char pad[20];
    DrawTarget* target;
};

void CasMediator_DrawSim(CasMediator* self) {
    if (self->target != 0) {
        self->target->V11();
    }
}
