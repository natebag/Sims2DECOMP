/* auto at 0x801527F4 (48B) [vtable_dtor_48B] */

typedef unsigned char u8;
extern int VT_801527F4[];
void base_801527F4(u8*);
void dtor_801527F4(u8* self) {
    *(int**)(self + 0x0) = VT_801527F4;
    base_801527F4(self);
}
