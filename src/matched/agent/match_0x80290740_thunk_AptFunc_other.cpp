extern int target_0x802906C4(void *self);

struct Thunk_AptFunc_other {
    int func();
};

int Thunk_AptFunc_other::func() {
    return target_0x802906C4(this);
}
