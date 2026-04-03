extern int VT[];
void del_fn(void *);
void d_BloomNGC_BloomNGC(char *self, int __in_chrg) {
    *(int **)(self + 16) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
