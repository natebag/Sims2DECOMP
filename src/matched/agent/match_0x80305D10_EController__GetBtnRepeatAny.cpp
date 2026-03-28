struct EController {
    unsigned int GetBtnRepeatMask(unsigned int filterMask);
    int GetBtnResultAny(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnRepeatAny(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnRepeatAny(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnRepeatMask(filterMask);
    return GetBtnResultAny(mask, false, btn);
}
