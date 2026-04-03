extern int VT_cFixedWorld_cFixedWorld[];
void del_cFixedWorld_cFixedWorld(void *);
void dtor_cFixedWorld_cFixedWorld(char *self, int __in_chrg) {
    *(int **)self = VT_cFixedWorld_cFixedWorld;
    if (__in_chrg & 1) {
        del_cFixedWorld_cFixedWorld(self);
    }
}
