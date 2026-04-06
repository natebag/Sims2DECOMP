// 0x8030429C EController::SwapAxes (24b)

struct EController_SA {
    char pad[0x18C];
    int m_axisSwap[4];
    void SwapAxes(int axis);
};

void EController_SA::SwapAxes(int axis) {
    m_axisSwap[axis] ^= 1;
}
