// FLAGS: -fno-elide-constructors
// 0x802CB96C (80 bytes) — VERIFIED MATCH
// EMutex::~EMutex()

extern int EMutex_vtable[];

void member_dtor_EMutex_fn(void *member, int arg);
void parent_dtor_EMutex_fn(void *self, int __in_chrg);

void EMutex_dtor(char *self, int __in_chrg) {
    *(int **)self = EMutex_vtable;
    member_dtor_EMutex_fn(self + 4, 2);
    parent_dtor_EMutex_fn(self, __in_chrg);
}
