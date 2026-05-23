// FLAGS: -msdata=eabi -G 8
/* 0x802EB53C (52 bytes) - EAnimController::CallbackIntermediateComputeMatrices(EMat4&) */
extern int g_frameCounter;

class EAnimController {
public:
    char pad_0[48];
    int m_field_48;

    void ComputeMatrices(void* param);
    void CallbackICM(void* param);
};

void EAnimController::CallbackICM(void* param) {
    ComputeMatrices(param);
    m_field_48 = g_frameCounter;
}
