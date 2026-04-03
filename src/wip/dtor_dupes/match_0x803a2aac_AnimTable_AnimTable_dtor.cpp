extern int VT_AnimTable_AnimTable[];
void del_AnimTable_AnimTable(void *);
void dtor_AnimTable_AnimTable(char *self, int __in_chrg) {
    *(int **)self = VT_AnimTable_AnimTable;
    if (__in_chrg & 1) {
        del_AnimTable_AnimTable(self);
    }
}
