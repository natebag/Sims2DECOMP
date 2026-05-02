// 0x802D7B9C (68B) ESleep::~ESleep(void)
// Variant L: SI deleting-dtor, parent ~ESemaphore with flag=2.

void ESemaphore_dtor(void* obj, int flag);
void __builtin_delete(void* p);

struct ESleep {
    void dtor(int flag);
};

void ESleep::dtor(int flag) {
    ESemaphore_dtor(this, 2);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
