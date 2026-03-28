extern int target_0x80238480(void *self);

struct Thunk_cSoundPlayer_func {
    int func();
};

int Thunk_cSoundPlayer_func::func() {
    return target_0x80238480(this);
}
