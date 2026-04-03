extern int VT_Family_Family[];
void del_Family_Family(void *);
void dtor_Family_Family(char *self, int __in_chrg) {
    *(int **)self = VT_Family_Family;
    if (__in_chrg & 1) {
        del_Family_Family(self);
    }
}
