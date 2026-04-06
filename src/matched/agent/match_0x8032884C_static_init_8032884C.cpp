// 0x8032884C __static_initialization_and_destruction_0 (108b)
extern char g_obj_8032884C[];
extern int g_vt_8032884C[];
void g_ctor_8032884C(void*);
void g_dtor_8032884C(void*, int);

void static_init_8032884C(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_8032884C;
        g_ctor_8032884C(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_8032884C;
    } else {
        g_dtor_8032884C(g_obj_8032884C, 2);
    }
}
