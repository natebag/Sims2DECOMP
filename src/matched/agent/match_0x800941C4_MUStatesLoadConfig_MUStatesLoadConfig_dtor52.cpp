// 0x800941C4 MUStatesLoadConfig_MUStatesLoadConfig_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_MUStatesLoadConfig_MUStatesLoadConfig(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
