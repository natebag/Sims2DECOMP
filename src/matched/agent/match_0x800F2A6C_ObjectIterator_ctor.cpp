// 0x800F2A6C ObjectIterator::ObjectIterator (20b)

struct ObjectIterator {
    int f0;
    int f4;
    int f8;
    ObjectIterator(int p2, int p3);
};

ObjectIterator::ObjectIterator(int p2, int p3) {
    ObjectIterator* p = this;
    p->f0 = p2;
    p->f4 = p2;
    p->f8 = p3;
}
