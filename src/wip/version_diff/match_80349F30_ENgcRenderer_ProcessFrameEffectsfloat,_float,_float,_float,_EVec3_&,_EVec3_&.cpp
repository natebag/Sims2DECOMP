// 0x80349F30 (12 bytes)
class ENgcRenderer {
public:
    struct TypeInfo* ProcessFrameEffects() const;
};

struct TypeInfo;
extern TypeInfo __ENgcRenderer_TypeInfo;

struct TypeInfo* ENgcRenderer::ProcessFrameEffects() const {
    return &__ENgcRenderer_TypeInfo;
}
