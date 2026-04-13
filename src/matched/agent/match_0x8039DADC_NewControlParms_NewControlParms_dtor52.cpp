// 0x8039DADC NewControlParms_NewControlParms_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_NewControlParms_NewControlParms(char *self, int __in_chrg) {
    *(int **)(self + 192) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
