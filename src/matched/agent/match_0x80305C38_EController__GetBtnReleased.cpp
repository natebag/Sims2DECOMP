struct EController {
    unsigned int GetBtnReleasedMask(unsigned int filterMask);
    int GetBtnResult(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnReleased(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnReleased(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnReleasedMask(filterMask);
    return GetBtnResult(mask, false, btn);
}
