// FLAGS: -msdata=eabi -G 8
// 0x802EA28C EAnimController::PrepareForCollision (64b)
extern void ComputeInverse(void*, void*, int);
extern int g_frameCounter;

struct EAnimController {
    char pad[40];
    int field_40;
    char pad2[4];
    int field_48;
};

void PrepareForCollision(EAnimController* self, void* mat) {
    int frame = g_frameCounter;
    if (self->field_40 != frame) {
        if (self->field_48 != frame) {
            frame--;
        }
    }
    ComputeInverse(self, mat, frame);
}
