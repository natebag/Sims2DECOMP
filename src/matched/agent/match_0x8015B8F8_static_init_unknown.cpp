/* __static_initialization_and_destruction_0 - 0x8015B8F8 - 112 bytes */

void Ctor_804874C0(void*, void*, unsigned int, int, int);
void Atexit_804874C0(void*, int);

extern char gObj_804874C0[];
extern char gParam_80487517[];
extern char gParam_803EE01C[];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            Ctor_804874C0(gObj_804874C0, gParam_803EE01C, (unsigned int)gParam_80487517 & 0xFFFFFFC0, 104, 5);
        } else {
            Atexit_804874C0(gObj_804874C0, 2);
        }
    }
}
