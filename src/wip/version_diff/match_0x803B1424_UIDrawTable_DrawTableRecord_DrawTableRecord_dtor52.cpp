extern int VT[];
void del_fn(void *);
void d_UIDrawTable_DrawTableRecord_DrawTableRecord(char *self, int __in_chrg) {
    *(int **)(self + 20) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
