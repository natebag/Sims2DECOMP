// FLAGS: -fno-elide-constructors
extern int g_obj_8007D53C[];
extern void ctor_8007D53C(void*);
extern void dtor_8007D53C(void*, int);

void func_8007D53C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8007D53C(g_obj_8007D53C);
    } else {
        dtor_8007D53C(g_obj_8007D53C, 2);
    }
}
