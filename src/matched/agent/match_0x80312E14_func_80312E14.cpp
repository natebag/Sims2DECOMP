// FLAGS: -fno-elide-constructors
extern int g_obj_80312E14[];
extern void ctor_80312E14(void*);
extern void dtor_80312E14(void*, int);

void func_80312E14(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_80312E14(g_obj_80312E14);
    } else {
        dtor_80312E14(g_obj_80312E14, 2);
    }
}
