extern int VT[];
void del_fn(void *);
void d_ERenderSurface_ERenderSurface(char *self, int __in_chrg) {
    *(int **)(self + 32) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
