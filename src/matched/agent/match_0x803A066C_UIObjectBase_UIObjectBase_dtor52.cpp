extern int VT[];
void del_fn(void *);
void d_UIObjectBase_UIObjectBase(char *self, int __in_chrg) {
    *(int **)(self + 128) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
