extern int VT_RelMatrix_RelMatrix[];
void del_RelMatrix_RelMatrix(void *);
void dtor_RelMatrix_RelMatrix(char *self, int __in_chrg) {
    *(int **)self = VT_RelMatrix_RelMatrix;
    if (__in_chrg & 1) {
        del_RelMatrix_RelMatrix(self);
    }
}
