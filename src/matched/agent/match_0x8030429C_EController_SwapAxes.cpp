// 0x8030429C EController::SwapAxes (24b)

struct EController {
    char pad[0x18C];
    int m_axisSwap[4];
    void SwapAxes(int axis);
};

void EController::SwapAxes(int axis) {
    m_axisSwap[axis] ^= 1;
}
