struct EController {
    unsigned int GetBtnPressedMask(unsigned int filterMask);
    unsigned int GetBtnDownMask(unsigned int filterMask);
    int GetCmdResult(unsigned int cmd, unsigned int mask1, unsigned int mask2, bool exclusive);
    int GetCmdPressed(unsigned int cmd, unsigned int filterMask);
};

int EController::GetCmdPressed(unsigned int cmd, unsigned int filterMask) {
    unsigned int mask1 = GetBtnPressedMask(filterMask);
    unsigned int mask2 = GetBtnDownMask(filterMask);
    return GetCmdResult(cmd, mask1, mask2, false);
}
