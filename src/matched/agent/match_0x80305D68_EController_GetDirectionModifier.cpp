// 0x80305D68 EController::GetDirectionModifier (24b)
// DOL has stick parameter first (multiplied by 4), then axis (multiplied by 8)
// This suggests array layout: int m_dirModifier[axis][stick] or the params are swapped

struct EController {
    char pad[0x194];
    int m_dirModifier[2][2];  // layout matches [axis][stick] access pattern
    int GetDirectionModifier(int axis, int stick);
};

int EController::GetDirectionModifier(int axis, int stick) {
    return m_dirModifier[axis][stick];  // axis has stride of 8 (2 ints), stick has stride of 4
}
