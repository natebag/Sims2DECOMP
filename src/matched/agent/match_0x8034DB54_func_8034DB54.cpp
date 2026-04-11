// FLAGS: -fno-elide-constructors
extern int g_obj_8034DB54[];
extern void ctor_8034DB54(void*);
extern void dtor_8034DB54(void*, int);

void func_8034DB54(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8034DB54(g_obj_8034DB54);
    } else {
        dtor_8034DB54(g_obj_8034DB54, 2);
    }
}
