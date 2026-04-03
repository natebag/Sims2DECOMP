extern int VT_AnimTableImpl_AnimTableImpl[];
void del_AnimTableImpl_AnimTableImpl(void *);
void dtor_AnimTableImpl_AnimTableImpl(char *self, int __in_chrg) {
    *(int **)self = VT_AnimTableImpl_AnimTableImpl;
    if (__in_chrg & 1) {
        del_AnimTableImpl_AnimTableImpl(self);
    }
}
