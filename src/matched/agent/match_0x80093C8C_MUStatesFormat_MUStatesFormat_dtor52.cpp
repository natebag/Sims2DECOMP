// 0x0x80093C8C match_0x80093C8C_MUStatesFormat_MUStatesFormat_dtor52.cpp (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_MUStatesFormat_MUStatesFormat(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
