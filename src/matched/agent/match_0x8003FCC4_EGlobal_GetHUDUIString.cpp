// 0x8003FCC4 EGlobal::GetHUDUIString (112b)
extern char g_key_hud[];
extern char g_tdb_GetHUDUIString[];
extern void* g_sda_fb_GetHUDUIString;

void* qd_gt_GetHUDUIString(void*, char*);
void* qd_gr_GetHUDUIString(void*, void*, char*);

void* GetHUDUIString_test(int* retptr, char* self, char* nm) {
    if (nm != 0) {
        void* table = qd_gt_GetHUDUIString(*(void**)(self + 232), g_key_hud);
        void* row = qd_gr_GetHUDUIString(*(void**)g_tdb_GetHUDUIString, table, nm);
        if (row != 0) {
            *retptr = *(int*)row;
        } else {
            *retptr = (int)g_sda_fb_GetHUDUIString;
        }
    }
    return retptr;
}
