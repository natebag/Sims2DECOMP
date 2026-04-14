/* ResourceBehaviorTree::QueryInterface(unsigned int, void **) - 0x8015B1F8 - 112 bytes */

struct ResourceBehaviorTree {
    int QueryInterface(unsigned int iid, void **output);
};

int ResourceBehaviorTree::QueryInterface(unsigned int iid, void **output) {
    if (!output) return 0;
    if (iid == 1 || iid == 0x2BEB2426U) {
        int *vtable = *(int **)this;
        short delta = *(short *)((char *)vtable + 16);
        void (*func)(void *, unsigned int) = (void (*)(void *, unsigned int))vtable[5];
        func((char *)this + delta, iid);
        *output = this;
        return 1;
    }
    return 0;
}
