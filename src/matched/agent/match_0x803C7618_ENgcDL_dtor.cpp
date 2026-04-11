// 0x803C7618 (80 bytes) — VERIFIED MATCH
// ENgcDL::~ENgcDL()

extern int ENgcDL_vtable[];

void cleanup_ENgcDL_fn(void *self, int arg);
void delete_ENgcDL_fn(void *self);

void ENgcDL_dtor(char *self, int __in_chrg) {
    *(int **)(self + 100) = ENgcDL_vtable;
    cleanup_ENgcDL_fn(self, 0);
    if (__in_chrg & 1) {
        delete_ENgcDL_fn(self);
    }
}
