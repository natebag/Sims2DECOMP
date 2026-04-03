extern int VT_House_House[];
void del_House_House(void *);
void dtor_House_House(char *self, int __in_chrg) {
    *(int **)self = VT_House_House;
    if (__in_chrg & 1) {
        del_House_House(self);
    }
}
