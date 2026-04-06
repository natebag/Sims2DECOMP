extern void* gSpriteRenderer;
struct SpriteSlot { char pad[0x18]; int m_spriteIdx; };
extern "C" void changeSprite(void* renderer, SpriteSlot* slot);
void SpriteSlot_ChangeToSprite(SpriteSlot* self, int idx) {
    self->m_spriteIdx = idx;
    changeSprite(gSpriteRenderer, self);
}
