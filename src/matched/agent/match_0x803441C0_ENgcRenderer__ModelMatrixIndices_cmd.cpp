// ENgcRenderer::ModelMatrixIndices(EDLEntry *) at 0x803441C0 (76B)
// EDLEntry dispatcher -- iterates 4 byte indices, calls per-slot setter.

class ENgcRenderer_MMI {
public:
    void ModelMatrixIndices(void* cmd);
    void ModelMatrixIndex(int index, int value);
};

void ENgcRenderer_MMI::ModelMatrixIndices(void* cmd) {
    unsigned char* indices = (unsigned char*)cmd + 4;
    for (int i = 0; i <= 3; i++) {
        ModelMatrixIndex(i, indices[i]);
    }
}
