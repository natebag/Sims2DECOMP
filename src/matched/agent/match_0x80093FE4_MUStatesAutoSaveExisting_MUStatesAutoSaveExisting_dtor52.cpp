// 0x80093FE4 MUStatesAutoSaveExisting_MUStatesAutoSaveExisting_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_MUStatesAutoSaveExisting_MUStatesAutoSaveExisting(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
