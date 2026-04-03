extern int VT_ObjFnTable_ObjFnTable[];
void del_ObjFnTable_ObjFnTable(void *);
void dtor_ObjFnTable_ObjFnTable(char *self, int __in_chrg) {
    *(int **)self = VT_ObjFnTable_ObjFnTable;
    if (__in_chrg & 1) {
        del_ObjFnTable_ObjFnTable(self);
    }
}
