extern int VT[];
void del_fn(void *);
void d_UI2D_UI2DRecord_UI2DRecord(char *self, int __in_chrg) {
    *(int **)(self + 44) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
