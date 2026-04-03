extern int VT_IBaseSimInstance_IBaseSimInstance[];
void del_IBaseSimInstance_IBaseSimInstance(void *);
void dtor_IBaseSimInstance_IBaseSimInstance(char *self, int __in_chrg) {
    *(int **)self = VT_IBaseSimInstance_IBaseSimInstance;
    if (__in_chrg & 1) {
        del_IBaseSimInstance_IBaseSimInstance(self);
    }
}
