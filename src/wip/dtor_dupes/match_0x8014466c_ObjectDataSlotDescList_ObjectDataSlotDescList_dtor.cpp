extern int VT_ObjectDataSlotDescList_ObjectDataSlotDescList[];
void del_ObjectDataSlotDescList_ObjectDataSlotDescList(void *);
void dtor_ObjectDataSlotDescList_ObjectDataSlotDescList(char *self, int __in_chrg) {
    *(int **)self = VT_ObjectDataSlotDescList_ObjectDataSlotDescList;
    if (__in_chrg & 1) {
        del_ObjectDataSlotDescList_ObjectDataSlotDescList(self);
    }
}
