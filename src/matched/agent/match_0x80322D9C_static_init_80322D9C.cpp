// 0x80322D9C __static_initialization_and_destruction_0 (108b)
extern char g_obj_80322D9C[];
extern int g_vt_80322D9C[];
void g_ctor_80322D9C(void*);
void g_dtor_80322D9C(void*, int);

void static_init_80322D9C(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80322D9C;
        g_ctor_80322D9C(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80322D9C;
    } else {
        g_dtor_80322D9C(g_obj_80322D9C, 2);
    }
}
