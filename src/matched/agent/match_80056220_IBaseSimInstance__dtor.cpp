/* IBaseSimInstance::~IBaseSimInstance(void) at 0x80056220 (52B) */

extern int IBaseSimInstance_vtable[];
void __builtin_delete(void *ptr);

void IBaseSimInstance_dtor(void *self, int delFlag) {
    *(int *)self = (int)IBaseSimInstance_vtable;
    if (delFlag & 1) {
        __builtin_delete(self);
    }
}
