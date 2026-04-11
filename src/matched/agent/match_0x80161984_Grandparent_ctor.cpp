// 0x80161984 Grandparent::Grandparent (20b)

struct Grandparent {
    int f0;
    int f4;
    Grandparent();
};

Grandparent::Grandparent() {
    Grandparent* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
