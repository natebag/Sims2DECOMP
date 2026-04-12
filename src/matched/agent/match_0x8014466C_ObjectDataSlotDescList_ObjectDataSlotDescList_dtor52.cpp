// 0x8014466C ObjectDataSlotDescList_ObjectDataSlotDescList_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_ObjectDataSlotDescList_ObjectDataSlotDescList(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
