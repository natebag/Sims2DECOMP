extern int VT_ObjectFolder_ObjectFolder[];
void del_ObjectFolder_ObjectFolder(void *);
void dtor_ObjectFolder_ObjectFolder(char *self, int __in_chrg) {
    *(int **)self = VT_ObjectFolder_ObjectFolder;
    if (__in_chrg & 1) {
        del_ObjectFolder_ObjectFolder(self);
    }
}
