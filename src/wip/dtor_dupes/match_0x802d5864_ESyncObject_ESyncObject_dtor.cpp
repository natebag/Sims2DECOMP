extern int VT_ESyncObject_ESyncObject[];
void del_ESyncObject_ESyncObject(void *);
void dtor_ESyncObject_ESyncObject(char *self, int __in_chrg) {
    *(int **)self = VT_ESyncObject_ESyncObject;
    if (__in_chrg & 1) {
        del_ESyncObject_ESyncObject(self);
    }
}
