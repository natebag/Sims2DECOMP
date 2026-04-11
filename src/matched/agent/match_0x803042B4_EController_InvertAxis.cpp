// 0x803042B4 EController::InvertAxis (32b)

struct EController {
    char pad[0x194];
    int m_dirModifier[2][2];  // [axis][stick]
    void InvertAxis(int axis, int stick);
};

void EController::InvertAxis(int axis, int stick) {
    m_dirModifier[axis][stick] = -m_dirModifier[axis][stick];
}
