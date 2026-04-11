extern int VT[];
void del_fn(void *);
void d_GetVar_LockedStatus_GetVar_LockedStatus(char *self, int __in_chrg) {
    *(int **)(self + 8) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
