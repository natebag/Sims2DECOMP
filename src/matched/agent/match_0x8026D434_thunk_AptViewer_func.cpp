extern int target_0x8026CA44(void *self);

struct Thunk_AptViewer_func {
    int func();
};

int Thunk_AptViewer_func::func() {
    return target_0x8026CA44(this);
}
