extern int VT_IconGroup_IconGroup[];
void del_IconGroup_IconGroup(void *);
void dtor_IconGroup_IconGroup(char *self, int __in_chrg) {
    *(int **)self = VT_IconGroup_IconGroup;
    if (__in_chrg & 1) {
        del_IconGroup_IconGroup(self);
    }
}
