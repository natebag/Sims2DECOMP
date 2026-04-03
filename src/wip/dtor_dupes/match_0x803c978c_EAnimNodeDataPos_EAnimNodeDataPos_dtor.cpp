extern int VT_EAnimNodeDataPos_EAnimNodeDataPos[];
void del_EAnimNodeDataPos_EAnimNodeDataPos(void *);
void dtor_EAnimNodeDataPos_EAnimNodeDataPos(char *self, int __in_chrg) {
    *(int **)self = VT_EAnimNodeDataPos_EAnimNodeDataPos;
    if (__in_chrg & 1) {
        del_EAnimNodeDataPos_EAnimNodeDataPos(self);
    }
}
