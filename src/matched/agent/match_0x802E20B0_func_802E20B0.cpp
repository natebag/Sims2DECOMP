// FLAGS: -fno-elide-constructors
extern int g_obj_802E20B0[];
extern void ctor_802E20B0(void*);
extern void dtor_802E20B0(void*, int);

void func_802E20B0(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_802E20B0(g_obj_802E20B0);
    } else {
        dtor_802E20B0(g_obj_802E20B0, 2);
    }
}
