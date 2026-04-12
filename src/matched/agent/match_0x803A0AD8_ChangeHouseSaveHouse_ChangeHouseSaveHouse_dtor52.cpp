// 0x803A0AD8 ChangeHouseSaveHouse_ChangeHouseSaveHouse_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_ChangeHouseSaveHouse_ChangeHouseSaveHouse(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
