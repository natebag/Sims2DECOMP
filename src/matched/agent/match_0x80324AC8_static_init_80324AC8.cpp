// 0x80324AC8 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80324AC8[];
extern int g_vt_80324AC8[];
void g_ctor_80324AC8(void*);
void g_dtor_80324AC8(void*, int);

void static_init_80324AC8(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80324AC8;
        g_ctor_80324AC8(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80324AC8;
    } else {
        g_dtor_80324AC8(g_obj_80324AC8, 2);
    }
}
