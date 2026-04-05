typedef unsigned char u8;
extern int VT_ESimsApp[];
void base_dtor_ESimsApp(u8*);
void d_ESimsApp(u8* self) {
    *(int**)(self + 0x338) = VT_ESimsApp;
    base_dtor_ESimsApp(self);
}
