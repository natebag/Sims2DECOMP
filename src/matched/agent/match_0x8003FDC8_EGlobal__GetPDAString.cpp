// 0x8003FDC8 EGlobal::GetPDAString (112b)
extern char g_key_pda[];
extern char g_tdb_pda[];
extern void* g_sda_fb_pda;

void* qd_gt_pda(void*, char*);
void* qd_gr_pda(void*, void*, char*);

void* GetPDAString_impl(int* retptr, char* self, char* nm) {
    if (nm != 0) {
        void* table = qd_gt_pda(*(void**)(self + 232), g_key_pda);
        void* row = qd_gr_pda(*(void**)g_tdb_pda, table, nm);
        if (row != 0) {
            *retptr = *(int*)row;
        } else {
            *retptr = (int)g_sda_fb_pda;
        }
    }
    return retptr;
}
