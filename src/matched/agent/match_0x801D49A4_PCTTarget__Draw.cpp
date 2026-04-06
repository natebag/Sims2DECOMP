struct PCTTarget { char pad[0xE4]; void* m_renderer; };
extern "C" void drawPCT(void*, void*);
void PCTTarget_Draw(PCTTarget* self, void* erc) {
    if (self->m_renderer) { drawPCT(self->m_renderer, erc); }
}
