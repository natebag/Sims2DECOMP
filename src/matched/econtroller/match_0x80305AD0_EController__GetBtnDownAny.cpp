struct EController {
    unsigned int GetBtnDownMask(unsigned int filterMask);
    int GetBtnResultAny(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnDownAny(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnDownAny(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnDownMask(filterMask);
    return GetBtnResultAny(mask, false, btn);
}
