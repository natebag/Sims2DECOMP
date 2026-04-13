// FLAGS: -fno-schedule-insns
// 0x802CBD34 (80 bytes) � VERIFIED MATCH
// EThreadMutex::~EThreadMutex()

extern int EThreadMutex_vtable[];

void member_dtor_EThreadMutex_fn(void *member, int arg);
void parent_dtor_EThreadMutex_fn(void *self, int __in_chrg);

void EThreadMutex_dtor(char *self, int __in_chrg) {
    *(int **)self = EThreadMutex_vtable;
    member_dtor_EThreadMutex_fn(self + 28, 2);
    parent_dtor_EThreadMutex_fn(self, __in_chrg);
}
