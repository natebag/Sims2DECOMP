extern int VT_Language_Language[];
void del_Language_Language(void *);
void dtor_Language_Language(char *self, int __in_chrg) {
    *(int **)self = VT_Language_Language;
    if (__in_chrg & 1) {
        del_Language_Language(self);
    }
}
