// global_destructors keyed to EffectsPreRenderVisitor__Visit_Effects__FastParticleEmitter_ref
// Address: 0x8003E1C4 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

extern void cleanup_EffectsPreRenderVisitor(int a, unsigned short b);

void global_destructors_EffectsPreRenderVisitor() {
    cleanup_EffectsPreRenderVisitor(0, 0xFFFF);
}
