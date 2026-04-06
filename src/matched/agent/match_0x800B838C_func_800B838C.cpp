// FLAGS: -fno-elide-constructors
extern int g_obj_800B838C[];
extern void ctor_800B838C(void*);
extern void dtor_800B838C(void*, int);

void func_800B838C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_800B838C(g_obj_800B838C);
    } else {
        dtor_800B838C(g_obj_800B838C, 2);
    }
}
