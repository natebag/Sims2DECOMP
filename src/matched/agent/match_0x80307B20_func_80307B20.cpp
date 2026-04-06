// FLAGS: -fno-elide-constructors
extern int g_obj_80307B20[];
extern void ctor_80307B20(void*);
extern void dtor_80307B20(void*, int);

void func_80307B20(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_80307B20(g_obj_80307B20);
    } else {
        dtor_80307B20(g_obj_80307B20, 2);
    }
}
