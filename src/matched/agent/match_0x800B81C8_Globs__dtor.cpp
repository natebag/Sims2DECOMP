extern int g_globsFlag;
void del_globs(void*);
void d_Globs(void* self, int __in_chrg) {
    g_globsFlag = 0;
    if (__in_chrg & 1) {
        del_globs(self);
    }
}
