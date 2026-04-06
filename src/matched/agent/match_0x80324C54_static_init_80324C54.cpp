// 0x80324C54 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80324C54[];
extern int g_vt_80324C54[];
void g_ctor_80324C54(void*);
void g_dtor_80324C54(void*, int);

void static_init_80324C54(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80324C54;
        g_ctor_80324C54(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80324C54;
    } else {
        g_dtor_80324C54(g_obj_80324C54, 2);
    }
}
