// 0x803C247C EStorable::Construct(EStorable*) (16B)
// Set vtable pointer at offset 0

extern char EStorable_vtable[16];  // non-SDA via sized extern

struct EStorable;

void EStorable_Construct(EStorable* p) {
    *(void**)p = (void*)EStorable_vtable;
}
