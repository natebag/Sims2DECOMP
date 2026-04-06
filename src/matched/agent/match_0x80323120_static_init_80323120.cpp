// 0x80323120 __static_initialization_and_destruction_0 (108b)
extern char g_obj_80323120[];
extern int g_vt_80323120[];
void g_ctor_80323120(void*);
void g_dtor_80323120(void*, int);

void static_init_80323120(int initialize, unsigned int priority) {
    if (priority != 0xFFFFu) return;
    if (initialize != 0) {
        char* obj = g_obj_80323120;
        g_ctor_80323120(obj);
        *(int*)(obj + 0xD1C) = (int)g_vt_80323120;
    } else {
        g_dtor_80323120(g_obj_80323120, 2);
    }
}
