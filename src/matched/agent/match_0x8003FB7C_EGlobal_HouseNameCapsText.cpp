// 0x8003FB7C EGlobal::HouseNameCapsText (112b)
extern char g_key_hnc[];
extern char g_tdb_hnc[];
extern void* g_sda_fb_hnc;

void* qd_gt_hnc(void*, char*);
void* qd_gr_hnc(void*, void*, char*);

void* HouseNameCapsText_test(int* retptr, char* self, char* nm) {
    if (nm != 0) {
        void* table = qd_gt_hnc(*(void**)(self + 232), g_key_hnc);
        void* row = qd_gr_hnc(*(void**)g_tdb_hnc, table, nm);
        if (row != 0) {
            *retptr = *(int*)((char*)row + 12);
        } else {
            *retptr = (int)g_sda_fb_hnc;
        }
    }
    return retptr;
}
