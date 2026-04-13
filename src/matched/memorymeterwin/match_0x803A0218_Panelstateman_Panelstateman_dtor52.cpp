// 0x803A0218 Panelstateman_Panelstateman_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_Panelstateman_Panelstateman(char *self, int __in_chrg) {
    *(int **)(self + 4) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
