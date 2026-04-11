// FLAGS: -fno-elide-constructors
extern int g_obj_8009FFE0[];
extern void ctor_8009FFE0(void*);
extern void dtor_8009FFE0(void*, int);

void func_8009FFE0(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8009FFE0(g_obj_8009FFE0);
    } else {
        dtor_8009FFE0(g_obj_8009FFE0, 2);
    }
}
