// 0x80305778 (56b) - TEST
// EController::GetBtnDownMask

class EController {
public:
    char _pad[512];
    int* m_buttonState;
    
    int GetBaseButtonMask();
    int GetBtnDownMask(int mask);
};

int EController::GetBtnDownMask(int mask) {
    int baseMask = this->GetBaseButtonMask();
    return this->m_buttonState[2] & ~mask;
}
