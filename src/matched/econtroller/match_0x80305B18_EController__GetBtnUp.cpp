struct EController {
    unsigned int GetBtnUpMask(unsigned int filterMask);
    int GetBtnResult(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnUp(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnUp(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnUpMask(filterMask);
    return GetBtnResult(mask, false, btn);
}
