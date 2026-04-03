extern int VT_ReconObject_ReconObject[];
void del_ReconObject_ReconObject(void *);
void dtor_ReconObject_ReconObject(char *self, int __in_chrg) {
    *(int **)self = VT_ReconObject_ReconObject;
    if (__in_chrg & 1) {
        del_ReconObject_ReconObject(self);
    }
}
