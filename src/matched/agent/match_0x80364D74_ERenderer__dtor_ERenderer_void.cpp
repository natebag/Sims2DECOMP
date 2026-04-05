typedef unsigned char u8;
extern int VT_ERenderer__dtor_ERenderer_void[];
void base_ERenderer__dtor_ERenderer_void(u8*);
void ERenderer__dtor_ERenderer_void(u8* self) { *(int**)(self + 0x338) = VT_ERenderer__dtor_ERenderer_void; base_ERenderer__dtor_ERenderer_void(self); }
