// FLAGS: -fno-elide-constructors
extern int g_obj_80311C34[];
extern void ctor_80311C34(void*);
extern void dtor_80311C34(void*, int);

void func_80311C34(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_80311C34(g_obj_80311C34);
    } else {
        dtor_80311C34(g_obj_80311C34, 2);
    }
}
