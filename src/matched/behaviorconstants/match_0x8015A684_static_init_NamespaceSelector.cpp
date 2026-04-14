/* __static_initialization_and_destruction_0 - 0x8015A684 - 112 bytes */

void Ctor_80486928(void*, void*, unsigned int, int, int);
void Atexit_80486928(void*, int);

extern char gObj_80486928[];
extern char gParam_8048697F[];
extern char gParam_803EDF88[];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            Ctor_80486928(gObj_80486928, gParam_803EDF88, (unsigned int)gParam_8048697F & 0xFFFFFFC0, 32, 90);
        } else {
            Atexit_80486928(gObj_80486928, 2);
        }
    }
}
