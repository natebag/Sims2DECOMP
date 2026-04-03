extern int VT[];
void del_fn(void *);
void d_GetVar_Legacy_GetVar_Legacy(char *self, int __in_chrg) {
    *(int **)(self + 8) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
