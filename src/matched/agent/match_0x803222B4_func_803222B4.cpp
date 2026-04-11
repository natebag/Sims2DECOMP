// FLAGS: -fno-elide-constructors
extern int g_obj_803222B4[];
extern void ctor_803222B4(void*);
extern void dtor_803222B4(void*, int);

void func_803222B4(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_803222B4(g_obj_803222B4);
    } else {
        dtor_803222B4(g_obj_803222B4, 2);
    }
}
