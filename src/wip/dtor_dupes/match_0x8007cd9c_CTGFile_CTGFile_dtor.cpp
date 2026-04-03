extern int VT_CTGFile_CTGFile[];
void del_CTGFile_CTGFile(void *);
void dtor_CTGFile_CTGFile(char *self, int __in_chrg) {
    *(int **)self = VT_CTGFile_CTGFile;
    if (__in_chrg & 1) {
        del_CTGFile_CTGFile(self);
    }
}
