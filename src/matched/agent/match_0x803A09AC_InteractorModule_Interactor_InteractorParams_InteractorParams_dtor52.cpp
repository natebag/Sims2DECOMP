extern int VT[];
void del_fn(void *);
void d_InteractorModule_Interactor_InteractorParams_InteractorParams(char *self, int __in_chrg) {
    *(int **)(self + 16) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
