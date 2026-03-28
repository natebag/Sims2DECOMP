extern int target_0x80248084(void *self);

struct Thunk_CAS_func_1 {
    int func();
};

int Thunk_CAS_func_1::func() {
    return target_0x80248084(this);
}
