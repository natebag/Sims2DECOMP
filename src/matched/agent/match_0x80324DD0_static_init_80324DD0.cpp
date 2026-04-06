// 0x80324DD0 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80324DD0[];
extern int g_vt_80324DD0[];
void g_ctor_80324DD0(void*);
void g_dtor_80324DD0(void*, int);

void static_init_80324DD0(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80324DD0;
        g_ctor_80324DD0(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80324DD0;
    } else {
        g_dtor_80324DD0(g_obj_80324DD0, 2);
    }
}
