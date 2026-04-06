// FLAGS: -fno-elide-constructors
extern int g_obj_8036C8D0[];
extern void ctor_8036C8D0(void*);
extern void dtor_8036C8D0(void*, int);

void func_8036C8D0(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8036C8D0(g_obj_8036C8D0);
    } else {
        dtor_8036C8D0(g_obj_8036C8D0, 2);
    }
}
