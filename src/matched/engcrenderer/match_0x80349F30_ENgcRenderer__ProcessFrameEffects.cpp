// 0x80349F30 ENgcRenderer::ProcessFrameEffects(float, float, float, float, EVec3 &, EVec3 &) (12B)
// Pattern: 112-byte stack frame allocated and immediately freed, no body. Debug-stripped stub.

struct EVec3 { float x, y, z; };

class ENgcRenderer {
public:
    void ProcessFrameEffects(float, float, float, float, EVec3&, EVec3&);
};

void ENgcRenderer::ProcessFrameEffects(float, float, float, float, EVec3&, EVec3&) {
    char unused[104];
    (void)unused;
}
