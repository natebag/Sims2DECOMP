typedef unsigned char u8;
extern int VT_ENgcRenderSurface__dtor_ENgcRenderSurface_void[];
void base_ENgcRenderSurface__dtor_ENgcRenderSurface_void(u8*);
void ENgcRenderSurface__dtor_ENgcRenderSurface_void(u8* self) { *(int**)(self + 0x20) = VT_ENgcRenderSurface__dtor_ENgcRenderSurface_void; base_ENgcRenderSurface__dtor_ENgcRenderSurface_void(self); }
