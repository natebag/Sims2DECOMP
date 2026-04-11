extern int VT[];
void del_fn(void *);
void d_ReconObject_ReconObject(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
