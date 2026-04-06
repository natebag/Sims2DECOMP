// 0x800402BC EGlobal::GetMemCardString (112b)
extern char g_key_mc[];
extern char g_tdb_GetMemCardString[];
extern void* g_sda_fb_GetMemCardString;

void* qd_gt_GetMemCardString(void*, char*);
void* qd_gr_GetMemCardString(void*, void*, char*);

void* GetMemCardString_test(int* retptr, char* self, char* nm) {
    if (nm != 0) {
        void* table = qd_gt_GetMemCardString(*(void**)(self + 232), g_key_mc);
        void* row = qd_gr_GetMemCardString(*(void**)g_tdb_GetMemCardString, table, nm);
        if (row != 0) {
            *retptr = *(int*)row;
        } else {
            *retptr = (int)g_sda_fb_GetMemCardString;
        }
    }
    return retptr;
}
