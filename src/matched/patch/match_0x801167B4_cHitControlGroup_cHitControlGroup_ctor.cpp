// 0x801167B4 cHitControlGroup::cHitControlGroup (20b)

struct cHitControlGroup {
    int field_0;
    int field_4;
    cHitControlGroup(int p2);
};

cHitControlGroup::cHitControlGroup(int p2) {
    field_0 = p2;
    field_4 = 1024;
}
