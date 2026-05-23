struct EController {
    unsigned int GetBtnRepeatMask(unsigned int filterMask);
    int GetBtnResult(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnRepeat(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnRepeat(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnRepeatMask(filterMask);
    return GetBtnResult(mask, false, btn);
}
