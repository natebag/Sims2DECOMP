// 0x803042B4 EController::InvertAxis (32b)

struct EController_IA {
    char pad[0x194];
    int m_axisInvert[2][4];
    void InvertAxis(int axis, int sub);
};

void EController_IA::InvertAxis(int axis, int sub) {
    m_axisInvert[sub][axis] = -m_axisInvert[sub][axis];
}
