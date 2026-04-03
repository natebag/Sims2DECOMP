extern int VT[];
void del_fn(void *);
void d_PropTableImpl_PropTableImpl(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
