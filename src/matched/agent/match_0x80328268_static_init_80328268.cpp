// 0x80328268 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80328268[];
extern int g_vt_80328268[];
void g_ctor_80328268(void*);
void g_dtor_80328268(void*, int);

void static_init_80328268(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80328268;
        g_ctor_80328268(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80328268;
    } else {
        g_dtor_80328268(g_obj_80328268, 2);
    }
}
