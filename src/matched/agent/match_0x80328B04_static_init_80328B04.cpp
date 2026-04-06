// 0x80328B04 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80328B04[];
extern int g_vt_80328B04[];
void g_ctor_80328B04(void*);
void g_dtor_80328B04(void*, int);

void static_init_80328B04(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80328B04;
        g_ctor_80328B04(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80328B04;
    } else {
        g_dtor_80328B04(g_obj_80328B04, 2);
    }
}
