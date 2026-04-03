extern int VT_StringSet_StringSet[];
void del_StringSet_StringSet(void *);
void dtor_StringSet_StringSet(char *self, int __in_chrg) {
    *(int **)self = VT_StringSet_StringSet;
    if (__in_chrg & 1) {
        del_StringSet_StringSet(self);
    }
}
