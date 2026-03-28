struct EController {
    unsigned int GetBtnReleasedMask(unsigned int filterMask);
    int GetBtnResultAny(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnReleasedAny(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnReleasedAny(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnReleasedMask(filterMask);
    return GetBtnResultAny(mask, false, btn);
}
