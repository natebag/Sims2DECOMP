typedef unsigned char u8;
extern int VT_ENgcRC__dtor_ENgcRC_void[];
void base_ENgcRC__dtor_ENgcRC_void(u8*);
void ENgcRC__dtor_ENgcRC_void(u8* self) { *(int**)(self + 0x70) = VT_ENgcRC__dtor_ENgcRC_void; base_ENgcRC__dtor_ENgcRC_void(self); }
