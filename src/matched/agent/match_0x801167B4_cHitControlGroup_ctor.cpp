// 0x801167B4 cHitControlGroup::cHitControlGroup (20b)

struct cHitControlGroup {
    int f0;
    int f4;
    cHitControlGroup(int p2);
};

cHitControlGroup::cHitControlGroup(int p2) {
    cHitControlGroup* p = this;
    p->f0 = p2;
    p->f4 = 1024;
}
