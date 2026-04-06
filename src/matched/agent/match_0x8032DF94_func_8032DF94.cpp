// FLAGS: -fno-elide-constructors
extern int g_obj_8032DF94[];
extern void ctor_8032DF94(void*);
extern void dtor_8032DF94(void*, int);

void func_8032DF94(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8032DF94(g_obj_8032DF94);
    } else {
        dtor_8032DF94(g_obj_8032DF94, 2);
    }
}
