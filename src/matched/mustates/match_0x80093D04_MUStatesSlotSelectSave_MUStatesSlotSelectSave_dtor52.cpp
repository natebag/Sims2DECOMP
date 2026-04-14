// 0x0x80093D04 match_0x80093D04_MUStatesSlotSelectSave_MUStatesSlotSelectSave_dtor52.cpp (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_MUStatesSlotSelectSave_MUStatesSlotSelectSave(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
