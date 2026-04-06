/* static init + ctor/dtor + vtable store at 0x8022F968 (108B) */

extern char g_obj_8022F968[];
extern int g_vt_8022F968[];
extern void ctor_8022F968(void*);
extern void dtor_8022F968(void*, int);

void func_8022F968(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority != 0) {
        ctor_8022F968(g_obj_8022F968);
        *(int*)(g_obj_8022F968 + 0xD1C) = (int)g_vt_8022F968;
    } else {
        dtor_8022F968(g_obj_8022F968, 2);
    }
}
