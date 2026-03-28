extern int target_0x8026BE2C(void *self);

struct Thunk_AptCharInst_GetCamera {
    int func();
};

int Thunk_AptCharInst_GetCamera::func() {
    return target_0x8026BE2C(this);
}
