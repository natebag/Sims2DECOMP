// FLAGS: -fno-schedule-insns
// 0x803C3338 (52B)
extern int VT[];
void del_fn(void *);
void d_EMemoryBufferWriteStream_EMemoryBufferWriteStream(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
