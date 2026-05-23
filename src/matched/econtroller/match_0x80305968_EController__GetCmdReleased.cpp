struct EController {
    unsigned int GetBtnReleasedMask(unsigned int filterMask);
    unsigned int GetBtnUpMask(unsigned int filterMask);
    int GetCmdResult(unsigned int cmd, unsigned int mask1, unsigned int mask2, bool exclusive);
    int GetCmdReleased(unsigned int cmd, unsigned int filterMask);
};

int EController::GetCmdReleased(unsigned int cmd, unsigned int filterMask) {
    unsigned int mask1 = GetBtnReleasedMask(filterMask);
    unsigned int mask2 = GetBtnUpMask(filterMask);
    return GetCmdResult(cmd, mask1, mask2, false);
}
