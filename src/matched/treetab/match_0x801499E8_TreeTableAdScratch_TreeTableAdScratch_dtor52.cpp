// 0x801499E8 TreeTableAdScratch_TreeTableAdScratch_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_TreeTableAdScratch_TreeTableAdScratch(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
