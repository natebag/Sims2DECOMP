extern int VT_ObjectModule_ObjectModule[];
void del_ObjectModule_ObjectModule(void *);
void dtor_ObjectModule_ObjectModule(char *self, int __in_chrg) {
    *(int **)self = VT_ObjectModule_ObjectModule;
    if (__in_chrg & 1) {
        del_ObjectModule_ObjectModule(self);
    }
}
