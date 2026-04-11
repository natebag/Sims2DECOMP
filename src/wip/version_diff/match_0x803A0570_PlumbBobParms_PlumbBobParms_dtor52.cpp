extern int VT[];
void del_fn(void *);
void d_PlumbBobParms_PlumbBobParms(char *self, int __in_chrg) {
    *(int **)(self + 96) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
