// 0x802E6818 E3DWindow::SetFrustumType(int) (48B)

struct E3DWindow {
    char pad[796];
    int m_frustumType;
    void SetFrustumType(int t);
    void OnFrustumChanged();
};

void E3DWindow::SetFrustumType(int t) {
    int cur = m_frustumType;
    if (cur == t) return;
    m_frustumType = t;
    OnFrustumChanged();
}
