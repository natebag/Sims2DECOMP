// 0x803286E4 __static_initialization_and_destruction_0 (108b)
extern char g_obj_803286E4[];
extern int g_vt_803286E4[];
void g_ctor_803286E4(void*);
void g_dtor_803286E4(void*, int);

void static_init_803286E4(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_803286E4;
        g_ctor_803286E4(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_803286E4;
    } else {
        g_dtor_803286E4(g_obj_803286E4, 2);
    }
}
