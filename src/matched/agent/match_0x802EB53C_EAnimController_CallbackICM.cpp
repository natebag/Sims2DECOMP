// FLAGS: -msdata=eabi -G 8
// 0x802EB53C EAnimController::CallbackIntermediateComputeMatrices (52b)
extern void ComputeMatrices(void*, void*);
extern int g_frameCounter;

struct EAnimController { char pad[48]; int field_48; };

void CallbackICM(EAnimController* self, void* param) {
    ComputeMatrices(self, param);
    self->field_48 = g_frameCounter;
}
