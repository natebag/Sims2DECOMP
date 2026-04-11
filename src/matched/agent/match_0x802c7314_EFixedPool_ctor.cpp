// 0x802C7314 EFixedPool::EFixedPool (20b)

struct EFixedPool {
    int f0;
    int f4;
    EFixedPool();
};

EFixedPool::EFixedPool() {
    EFixedPool* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
