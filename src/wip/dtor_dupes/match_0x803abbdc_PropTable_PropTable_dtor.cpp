extern int VT_PropTable_PropTable[];
void del_PropTable_PropTable(void *);
void dtor_PropTable_PropTable(char *self, int __in_chrg) {
    *(int **)self = VT_PropTable_PropTable;
    if (__in_chrg & 1) {
        del_PropTable_PropTable(self);
    }
}
