// 0x8032B668 __static_initialization_and_destruction_0 (108b)
extern char g_obj_8032B668[];
extern int g_vt_8032B668[];
void g_ctor_8032B668(void*);
void g_dtor_8032B668(void*, int);

void static_init_8032B668(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_8032B668;
        g_ctor_8032B668(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_8032B668;
    } else {
        g_dtor_8032B668(g_obj_8032B668, 2);
    }
}
