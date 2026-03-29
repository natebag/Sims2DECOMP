void* alloc_8031B1EC(unsigned long);
void* ctor_8031B1EC(void*);

void* factory_8031B1EC() {
    return ctor_8031B1EC(alloc_8031B1EC(384));
}
