extern int VT_QuickStringSet_QuickStringSet[];
void del_QuickStringSet_QuickStringSet(void *);
void dtor_QuickStringSet_QuickStringSet(char *self, int __in_chrg) {
    *(int **)self = VT_QuickStringSet_QuickStringSet;
    if (__in_chrg & 1) {
        del_QuickStringSet_QuickStringSet(self);
    }
}
