// FLAGS: -fno-elide-constructors
extern int g_obj_80303DAC[];
extern void ctor_80303DAC(void*);
extern void dtor_80303DAC(void*, int);

void func_80303DAC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_80303DAC(g_obj_80303DAC);
    } else {
        dtor_80303DAC(g_obj_80303DAC, 2);
    }
}
