extern int VT_Careers_Careers[];
void del_Careers_Careers(void *);
void dtor_Careers_Careers(char *self, int __in_chrg) {
    *(int **)self = VT_Careers_Careers;
    if (__in_chrg & 1) {
        del_Careers_Careers(self);
    }
}
