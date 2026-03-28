/* __static_initialization_and_destruction_0 - 0x8011333C - 84 bytes */

void Ctor_80486590(void*);
void Atexit_80486590(void*, int);

extern char gObj_80486590[];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            Ctor_80486590(gObj_80486590);
        } else {
            Atexit_80486590(gObj_80486590, 2);
        }
    }
}
