struct EController {
    unsigned int GetBtnRepeatMask(unsigned int filterMask);
    unsigned int GetBtnDownMask(unsigned int filterMask);
    int GetCmdResult(unsigned int cmd, unsigned int mask1, unsigned int mask2, bool exclusive);
    int GetCmdRepeat(unsigned int cmd, unsigned int filterMask);
};

int EController::GetCmdRepeat(unsigned int cmd, unsigned int filterMask) {
    unsigned int mask1 = GetBtnRepeatMask(filterMask);
    unsigned int mask2 = GetBtnDownMask(filterMask);
    return GetCmdResult(cmd, mask1, mask2, false);
}
