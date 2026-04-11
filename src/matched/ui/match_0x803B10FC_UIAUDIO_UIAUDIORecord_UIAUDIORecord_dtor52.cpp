// FLAGS: -fno-schedule-insns
// 0x803B10FC (52B)
extern int VT[];
void del_fn(void *);
void d_UIAUDIO_UIAUDIORecord_UIAUDIORecord(char *self, int __in_chrg) {
    *(int **)(self + 20) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
