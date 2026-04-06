// FLAGS: -fno-elide-constructors
extern int g_obj_8032CB1C[];
extern void ctor_8032CB1C(void*);
extern void dtor_8032CB1C(void*, int);

void func_8032CB1C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8032CB1C(g_obj_8032CB1C);
    } else {
        dtor_8032CB1C(g_obj_8032CB1C, 2);
    }
}
