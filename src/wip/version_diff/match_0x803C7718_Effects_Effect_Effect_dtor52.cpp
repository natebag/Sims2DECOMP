extern int VT[];
void del_fn(void *);
void d_Effects_Effect_Effect(char *self, int __in_chrg) {
    *(int **)(self + 324) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
