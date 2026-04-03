extern int VT_EStorable_EStorable[];
void del_EStorable_EStorable(void *);
void dtor_EStorable_EStorable(char *self, int __in_chrg) {
    *(int **)self = VT_EStorable_EStorable;
    if (__in_chrg & 1) {
        del_EStorable_EStorable(self);
    }
}
