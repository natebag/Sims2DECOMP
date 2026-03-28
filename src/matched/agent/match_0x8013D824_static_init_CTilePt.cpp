/* __static_initialization_and_destruction_0 - 0x8013D824 - 84 bytes */

void Ctor_804868A8(void*);
void Atexit_804868A8(void*, int);

extern char gObj_804868A8[];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            Ctor_804868A8(gObj_804868A8);
        } else {
            Atexit_804868A8(gObj_804868A8, 2);
        }
    }
}
