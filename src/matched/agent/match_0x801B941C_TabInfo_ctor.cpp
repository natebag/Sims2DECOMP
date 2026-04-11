// 0x801B941C INGTarget::TabInfo::TabInfo (24b)

struct TabInfo {
    int f0;
    short f4;
    int f8;
    TabInfo();
};

TabInfo::TabInfo() {
    TabInfo* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
}
