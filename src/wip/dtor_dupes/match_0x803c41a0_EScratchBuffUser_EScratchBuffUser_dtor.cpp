extern int VT_EScratchBuffUser_EScratchBuffUser[];
void del_EScratchBuffUser_EScratchBuffUser(void *);
void dtor_EScratchBuffUser_EScratchBuffUser(char *self, int __in_chrg) {
    *(int **)self = VT_EScratchBuffUser_EScratchBuffUser;
    if (__in_chrg & 1) {
        del_EScratchBuffUser_EScratchBuffUser(self);
    }
}
