// 0x800940D4 MUStatesTransitionAutoSaveExisting_MUStatesTransitionAutoSaveExisting_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_MUStatesTransitionAutoSaveExisting_MUStatesTransitionAutoSaveExisting(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
