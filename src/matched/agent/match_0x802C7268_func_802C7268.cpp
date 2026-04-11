// FLAGS: -fno-elide-constructors
extern int g_obj_802C7268[];
extern void ctor_802C7268(void*);
extern void dtor_802C7268(void*, int);

void func_802C7268(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_802C7268(g_obj_802C7268);
    } else {
        dtor_802C7268(g_obj_802C7268, 2);
    }
}
