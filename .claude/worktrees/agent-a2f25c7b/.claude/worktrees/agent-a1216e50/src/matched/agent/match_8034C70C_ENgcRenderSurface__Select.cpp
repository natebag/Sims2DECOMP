/* 0x8034C70C (12 bytes) - ENgcRenderSurface::Select(void) */
class ENgcRenderSurface { char pad[36]; int m_selected; public: void Select(); };
void ENgcRenderSurface::Select() { m_selected = 1; }
