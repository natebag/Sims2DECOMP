/* global constructor/destructor 84B template — 0x8003E0EC */
// FLAGS: -fno-elide-constructors
extern int g_obj_8003E0EC[];
extern void ctor_8003E0EC(void*);
extern void dtor_8003E0EC(void*, int);

void func_8003E0EC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8003E0EC(g_obj_8003E0EC);
    } else {
        dtor_8003E0EC(g_obj_8003E0EC, 2);
    }
}
