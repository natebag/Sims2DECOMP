// 0x803C62AC (80 bytes) — VERIFIED MATCH
// ERAudioStream::~ERAudioStream()

extern int ERAudioStream_vtable[];

void cleanup_ERAudioStream_fn(void *self, int arg);
void delete_ERAudioStream_fn(void *self);

void ERAudioStream_dtor(char *self, int __in_chrg) {
    *(int **)self = ERAudioStream_vtable;
    cleanup_ERAudioStream_fn(self, 0);
    if (__in_chrg & 1) {
        delete_ERAudioStream_fn(self);
    }
}
