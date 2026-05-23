// 0x803CA884 EAnimNodeDataPos::New(void) (40 B)
// PRAGMA_STUB: EAnimNodeDataPos::New(void)
void* alloc_803CA884(unsigned long);
void* ctor_803CA884(void*);

void* factory_803CA884() {
    return ctor_803CA884(alloc_803CA884(36));
}
