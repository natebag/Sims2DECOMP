// FLAGS: -msdata=eabi -G 8
// 0x80059BEC PlumbBob::Shutdown (88b)
extern void PlumbBobStack_Reset(void*);
extern void PlumbBobModel_dtor(void*, int);
extern void PlumbBob_DestroyParticleSystems(void*);

struct PlumbBob {
    char pad[356];
    void* model;
    int field_360;
    int field_364;
    char stack[16];
};

void PlumbBob_Shutdown(PlumbBob* self) {
    PlumbBobStack_Reset(&self->stack);
    void* mdl = self->model;
    self->field_364 = 0;
    if (mdl != 0) {
        PlumbBobModel_dtor(mdl, 3);
    }
    self->model = 0;
    PlumbBob_DestroyParticleSystems(self);
}
