struct EGraphics { char pad[0x90]; void* m_systemFont; };
extern "C" void ensureFontLoaded(EGraphics*);
void* EGraphics_GetSystemFont(EGraphics* self) {
    ensureFontLoaded(self);
    return self->m_systemFont;
}
