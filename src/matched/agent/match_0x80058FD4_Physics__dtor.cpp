// 0x80058FD4 (40B) Physics::~Physics(void)
// Deleting dtor — empty body, conditional __builtin_delete on flag&1.

void __builtin_delete(void* p);

struct Physics {
    void dtor(int flag);
};

void Physics::dtor(int flag) {
    if (flag & 1) {
        __builtin_delete(this);
    }
}
