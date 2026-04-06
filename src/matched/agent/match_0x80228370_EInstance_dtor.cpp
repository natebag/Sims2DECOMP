// FLAGS: -msdata=eabi -G 8
// 0x80228370 EInstance::~EInstance (88b)
extern int EInstance_VTable[];
extern int EInstanceBase_VTable[];
extern void RemoveFromLevel(void*);
extern void __builtin_delete(void*);

void EInstance_dtor(void* self, int flags) {
    *(int**)self = EInstance_VTable;
    RemoveFromLevel(self);
    *(int**)self = EInstanceBase_VTable;
    if (flags & 1) {
        __builtin_delete(self);
    }
}
