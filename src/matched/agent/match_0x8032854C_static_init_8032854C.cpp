// 0x8032854C __static_initialization_and_destruction_0 (108b)
extern char g_obj_8032854C[];
extern int g_vt_8032854C[];
void g_ctor_8032854C(void*);
void g_dtor_8032854C(void*, int);

void static_init_8032854C(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_8032854C;
        g_ctor_8032854C(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_8032854C;
    } else {
        g_dtor_8032854C(g_obj_8032854C, 2);
    }
}
