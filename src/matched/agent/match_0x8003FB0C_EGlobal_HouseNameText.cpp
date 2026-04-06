// 0x8003FB0C EGlobal::HouseNameText (112b)
extern char g_key_hn[];
extern char g_tdb_HouseNameText[];
extern void* g_sda_fb_HouseNameText;

void* qd_gt_HouseNameText(void*, char*);
void* qd_gr_HouseNameText(void*, void*, char*);

void* HouseNameText_test(int* retptr, char* self, char* nm) {
    if (nm != 0) {
        void* table = qd_gt_HouseNameText(*(void**)(self + 232), g_key_hn);
        void* row = qd_gr_HouseNameText(*(void**)g_tdb_HouseNameText, table, nm);
        if (row != 0) {
            *retptr = *(int*)row;
        } else {
            *retptr = (int)g_sda_fb_HouseNameText;
        }
    }
    return retptr;
}
