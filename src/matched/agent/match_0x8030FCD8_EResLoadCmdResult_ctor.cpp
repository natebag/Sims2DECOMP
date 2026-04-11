// 0x8030FCD8 EResLoadCmdResult::EResLoadCmdResult (24b)

struct EResLoadCmdResult {
    int f0;
    int f4;
    int f8;
    EResLoadCmdResult();
};

EResLoadCmdResult::EResLoadCmdResult() {
    EResLoadCmdResult* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
}
