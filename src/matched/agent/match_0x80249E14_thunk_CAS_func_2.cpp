extern int target_0x8024A890(void *self);

struct Thunk_CAS_func_2 {
    int func();
};

int Thunk_CAS_func_2::func() {
    return target_0x8024A890(this);
}
