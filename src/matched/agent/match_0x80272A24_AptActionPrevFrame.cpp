// AptActionInterpreter::_FunctionAptActionPrevFrame
// Address: 0x80272A24 | Size: 76 bytes
// Apt PrevFrame: loads context from arg, calls GotoFrame(frame-1), clears flag bit

struct AptContext {
    char pad_00[0x18];
    int m_frame;          // 0x18
    int m_flags;          // 0x1C
};

struct AptSprite {
    char pad_00[0x4C];
    AptContext* m_ctx;    // 0x4C
};

struct LocalCtx {
    char pad_00[0x04];
    AptSprite* m_sprite;  // 0x04
};

extern void AptSprite_GotoFrame(AptSprite* sprite, int frame);

void AptActionPrevFrame(void* interp, LocalCtx* ctx) {
    AptSprite* sprite = ctx->m_sprite;
    AptContext* aptCtx = sprite->m_ctx;
    int frame = aptCtx->m_frame - 1;
    AptSprite_GotoFrame(sprite, frame);
    aptCtx = sprite->m_ctx;
    aptCtx->m_flags = aptCtx->m_flags & ~0x40;
}
