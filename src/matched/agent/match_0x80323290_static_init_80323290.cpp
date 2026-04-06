// 0x80323290 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80323290[];
extern int g_vt_80323290[];
void g_ctor_80323290(void*);
void g_dtor_80323290(void*, int);

void static_init_80323290(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80323290;
        g_ctor_80323290(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80323290;
    } else {
        g_dtor_80323290(g_obj_80323290, 2);
    }
}
