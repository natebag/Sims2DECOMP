// 0x80324F4C __static_initialization_and_destruction_0 (108b)
extern char g_obj_80324F4C[];
extern int g_vt_80324F4C[];
void g_ctor_80324F4C(void*);
void g_dtor_80324F4C(void*, int);

void static_init_80324F4C(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80324F4C;
        g_ctor_80324F4C(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80324F4C;
    } else {
        g_dtor_80324F4C(g_obj_80324F4C, 2);
    }
}
