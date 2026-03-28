struct EController {
    unsigned int GetBtnDownMask(unsigned int filterMask);
    int GetCmdResult(unsigned int cmd, unsigned int mask1, unsigned int mask2, bool exclusive);
    int GetCmdDown(unsigned int cmd, unsigned int filterMask);
};

int EController::GetCmdDown(unsigned int cmd, unsigned int filterMask) {
    unsigned int mask1 = GetBtnDownMask(filterMask);
    unsigned int mask2 = GetBtnDownMask(filterMask);
    return GetCmdResult(cmd, mask1, mask2, false);
}
