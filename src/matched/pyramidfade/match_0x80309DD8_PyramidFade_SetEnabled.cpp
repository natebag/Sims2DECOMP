// 0x80309DD8 PyramidFade::SetEnabled(bool) (48B)
// Setter with change detection — if changed, store and notify

struct PyramidFade {
    char pad[156];
    int m_enabled;  // +156
    void SetEnabled(bool b);
    void OnChanged();
};

void PyramidFade::SetEnabled(bool b) {
    int cur = m_enabled;
    if (b == cur) return;
    m_enabled = b;
    OnChanged();
}
