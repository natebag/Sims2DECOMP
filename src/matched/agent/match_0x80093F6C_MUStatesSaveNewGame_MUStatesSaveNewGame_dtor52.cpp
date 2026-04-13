// 0x80093F6C MUStatesSaveNewGame_MUStatesSaveNewGame_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_MUStatesSaveNewGame_MUStatesSaveNewGame(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
