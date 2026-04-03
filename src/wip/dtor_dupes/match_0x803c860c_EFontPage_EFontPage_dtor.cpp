extern int VT_EFontPage_EFontPage[];
void del_EFontPage_EFontPage(void *);
void dtor_EFontPage_EFontPage(char *self, int __in_chrg) {
    *(int **)self = VT_EFontPage_EFontPage;
    if (__in_chrg & 1) {
        del_EFontPage_EFontPage(self);
    }
}
