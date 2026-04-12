// 0x803A0570 PlumbBobParms_PlumbBobParms_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_PlumbBobParms_PlumbBobParms(char *self, int __in_chrg) {
    *(int **)(self + 96) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
