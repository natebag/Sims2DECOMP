/* __static_initialization_and_destruction_0 - 0x80175428 - 84 bytes */

void Ctor_80487870(void*);
void Atexit_80487870(void*, int);

extern char gObj_80487870[];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            Ctor_80487870(gObj_80487870);
        } else {
            Atexit_80487870(gObj_80487870, 2);
        }
    }
}
