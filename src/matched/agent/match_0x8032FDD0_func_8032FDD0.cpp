// FLAGS: -fno-elide-constructors
extern int g_obj_8032FDD0[];
extern void ctor_8032FDD0(void*);
extern void dtor_8032FDD0(void*, int);

void func_8032FDD0(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8032FDD0(g_obj_8032FDD0);
    } else {
        dtor_8032FDD0(g_obj_8032FDD0, 2);
    }
}
