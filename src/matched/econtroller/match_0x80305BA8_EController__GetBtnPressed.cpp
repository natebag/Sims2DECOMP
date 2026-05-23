struct EController {
    unsigned int GetBtnPressedMask(unsigned int filterMask);
    int GetBtnResult(unsigned int mask, bool exclusive, unsigned int btn);
    int GetBtnPressed(unsigned int btn, unsigned int filterMask);
};

int EController::GetBtnPressed(unsigned int btn, unsigned int filterMask) {
    unsigned int mask = GetBtnPressedMask(filterMask);
    return GetBtnResult(mask, false, btn);
}
