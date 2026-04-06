// 0x803289AC __static_initialization_and_destruction_0 (108b)
extern char g_obj_803289AC[];
extern int g_vt_803289AC[];
void g_ctor_803289AC(void*);
void g_dtor_803289AC(void*, int);

void static_init_803289AC(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_803289AC;
        g_ctor_803289AC(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_803289AC;
    } else {
        g_dtor_803289AC(g_obj_803289AC, 2);
    }
}
