extern int VT_Slot_Slot[];
void del_Slot_Slot(void *);
void dtor_Slot_Slot(char *self, int __in_chrg) {
    *(int **)self = VT_Slot_Slot;
    if (__in_chrg & 1) {
        del_Slot_Slot(self);
    }
}
