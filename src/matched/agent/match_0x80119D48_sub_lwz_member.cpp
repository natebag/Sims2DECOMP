/* 36-byte wrapper at 0x80119D48: dereferences second arg and calls */

struct Ptr_80119D48 { void *ptr; };
extern void target_80119D48(void*, void*);

void sub_80119D48(void *a, Ptr_80119D48 *b) {
    target_80119D48(a, b->ptr);
}
