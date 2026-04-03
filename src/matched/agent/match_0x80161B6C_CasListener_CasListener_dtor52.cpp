extern int VT[];
void del_fn(void *);
void d_CasListener_CasListener(char *self, int __in_chrg) {
    *(int **)(self + 4) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
