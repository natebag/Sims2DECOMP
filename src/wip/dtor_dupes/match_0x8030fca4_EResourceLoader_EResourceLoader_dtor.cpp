extern int VT_EResourceLoader_EResourceLoader[];
void del_EResourceLoader_EResourceLoader(void *);
void dtor_EResourceLoader_EResourceLoader(char *self, int __in_chrg) {
    *(int **)self = VT_EResourceLoader_EResourceLoader;
    if (__in_chrg & 1) {
        del_EResourceLoader_EResourceLoader(self);
    }
}
