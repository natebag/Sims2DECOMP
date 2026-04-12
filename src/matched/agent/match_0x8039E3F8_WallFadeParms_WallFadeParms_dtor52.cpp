// 0x8039E3F8 WallFadeParms_WallFadeParms_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_WallFadeParms_WallFadeParms(char *self, int __in_chrg) {
    *(int **)(self + 44) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
