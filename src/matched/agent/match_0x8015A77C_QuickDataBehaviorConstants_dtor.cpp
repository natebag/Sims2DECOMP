// 0x8015A77C (80 bytes) — VERIFIED MATCH
// QuickDataBehaviorConstants::~QuickDataBehaviorConstants()

extern int QuickDataBehaviorConstants_vtable[];

void cleanup_QuickDataBehaviorConstants_fn(void *self, int arg);
void delete_QuickDataBehaviorConstants_fn(void *self);

void QuickDataBehaviorConstants_dtor(char *self, int __in_chrg) {
    *(int **)self = QuickDataBehaviorConstants_vtable;
    cleanup_QuickDataBehaviorConstants_fn(self, 0);
    if (__in_chrg & 1) {
        delete_QuickDataBehaviorConstants_fn(self);
    }
}
