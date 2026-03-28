struct EController {
    unsigned int GetBtnUpMask(unsigned int filterMask);
    int GetBtnResultAny(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnUpAny(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnUpAny(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnUpMask(filterMask);
    return GetBtnResultAny(mask, false, btn);
}
