struct EController {
    unsigned int GetBtnDownMask(unsigned int filterMask);
    int GetBtnResult(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnDown(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnDown(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnDownMask(filterMask);
    return GetBtnResult(mask, false, btn);
}
