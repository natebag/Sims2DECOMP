// FLAGS: -msdata=eabi -G 8
/* 0x802EA28C (64 bytes) - EAnimController::PrepareForCollision(EMat4&) */
extern int g_frameCounter;

class EAnimController {
public:
    char pad_0[40];
    int m_field_40;
    char pad_44[4];
    int m_field_48;

    void ComputeInverse(void* mat, int frame);
    void PrepareForCollision(void* mat);
};

void EAnimController::PrepareForCollision(void* mat) {
    int frame = g_frameCounter;
    if (m_field_40 != frame) {
        if (m_field_48 != frame) {
            frame--;
        }
    }
    ComputeInverse(mat, frame);
}
