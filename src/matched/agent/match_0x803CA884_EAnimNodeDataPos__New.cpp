void* alloc_803CA884(unsigned long);
void* ctor_803CA884(void*);

void* factory_803CA884() {
    return ctor_803CA884(alloc_803CA884(36));
}
