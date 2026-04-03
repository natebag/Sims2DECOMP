extern int VT_ObjectSlot_ObjectSlot[];
void del_ObjectSlot_ObjectSlot(void *);
void dtor_ObjectSlot_ObjectSlot(char *self, int __in_chrg) {
    *(int **)self = VT_ObjectSlot_ObjectSlot;
    if (__in_chrg & 1) {
        del_ObjectSlot_ObjectSlot(self);
    }
}
