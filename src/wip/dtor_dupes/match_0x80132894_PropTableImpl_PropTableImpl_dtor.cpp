extern int VT_PropTableImpl_PropTableImpl[];
void del_PropTableImpl_PropTableImpl(void *);
void dtor_PropTableImpl_PropTableImpl(char *self, int __in_chrg) {
    *(int **)self = VT_PropTableImpl_PropTableImpl;
    if (__in_chrg & 1) {
        del_PropTableImpl_PropTableImpl(self);
    }
}
