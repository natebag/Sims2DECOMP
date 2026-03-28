struct EController {
    unsigned int GetBtnPressedMask(unsigned int filterMask);
    int GetBtnResultAny(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnPressedAny(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnPressedAny(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnPressedMask(filterMask);
    return GetBtnResultAny(mask, false, btn);
}
