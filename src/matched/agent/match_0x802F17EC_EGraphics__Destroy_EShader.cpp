// 0x802F17EC EGraphics::Destroy(EShader*) (84B)
// MI-vcall via self->vtable slot 128 (vt+0x200/+0x204), with refcount-- after.
// Sibling-template from 0x802F18E4 EGraphics::Destroy (slot 16/132).
// First-try MATCH using existing MI-vcall pattern.

typedef unsigned char u8;
struct EShader;

void EGraphics_Destroy_Shader(u8* self, EShader* sh) {
    if (sh == 0) return;
    u8* vt = *(u8**)self;
    short adj = *(short*)(vt + 0x200);
    void (*fn)(u8*, EShader*) = *(void (**)(u8*, EShader*))(vt + 0x204);
    fn(self + adj, sh);
    *(int*)(self + 0x38) = *(int*)(self + 0x38) - 1;
}
