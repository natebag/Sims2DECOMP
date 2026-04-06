// 0x803283EC __static_initialization_and_destruction_0 (108b)
extern char g_obj_803283EC[];
extern int g_vt_803283EC[];
void g_ctor_803283EC(void*);
void g_dtor_803283EC(void*, int);

void static_init_803283EC(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_803283EC;
        g_ctor_803283EC(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_803283EC;
    } else {
        g_dtor_803283EC(g_obj_803283EC, 2);
    }
}
