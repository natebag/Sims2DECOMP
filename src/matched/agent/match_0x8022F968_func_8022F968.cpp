// 0x8022F968 __static_initialization_and_destruction_0 (108b)
extern char g_obj_8022F968[];
extern int g_vt_8022F968[];
void g_ctor_8022F968(void*);
void g_dtor_8022F968(void*, int);

void static_init_8022F968(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_8022F968;
        g_ctor_8022F968(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_8022F968;
    } else {
        g_dtor_8022F968(g_obj_8022F968, 2);
    }
}
