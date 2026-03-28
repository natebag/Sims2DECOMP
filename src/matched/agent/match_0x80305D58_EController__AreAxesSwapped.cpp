struct EController {
    char _p[0x18c];
    int m_axes[4];
    int AreAxesSwapped(int i);
};
int EController::AreAxesSwapped(int i) { return m_axes[i]; }
