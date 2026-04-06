// FLAGS: -fno-elide-constructors
extern int g_obj_802E3A44[];
extern void ctor_802E3A44(void*);
extern void dtor_802E3A44(void*, int);

void func_802E3A44(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_802E3A44(g_obj_802E3A44);
    } else {
        dtor_802E3A44(g_obj_802E3A44, 2);
    }
}
