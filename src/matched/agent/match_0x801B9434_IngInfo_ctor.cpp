// 0x801B9434 INGTarget::IngInfo::IngInfo (20b)

struct IngInfo {
    int f0;
    int f4;
    IngInfo();
};

IngInfo::IngInfo() {
    IngInfo* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
