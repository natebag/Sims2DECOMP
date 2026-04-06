// 0x80322C18 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80322C18[];
extern int g_vt_80322C18[];
void g_ctor_80322C18(void*);
void g_dtor_80322C18(void*, int);

void static_init_80322C18(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80322C18;
        g_ctor_80322C18(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80322C18;
    } else {
        g_dtor_80322C18(g_obj_80322C18, 2);
    }
}
