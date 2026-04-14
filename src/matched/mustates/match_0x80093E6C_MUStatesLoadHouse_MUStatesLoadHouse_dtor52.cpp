// 0x80093E6C MUStatesLoadHouse_MUStatesLoadHouse_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_MUStatesLoadHouse_MUStatesLoadHouse(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
