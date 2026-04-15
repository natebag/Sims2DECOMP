// 0x80164F64 CasNpcEditor::IsLoadInProgress() const (28B) — float > threshold

extern char g_casLoadProgressThreshold[16];  // non-SDA float

struct CasNpcEditor {
    char pad[20];
    float m_progress;
    int IsLoadInProgress() const;
};

int CasNpcEditor::IsLoadInProgress() const {
    float v = m_progress;
    float thr = *(float*)g_casLoadProgressThreshold;
    return v > thr;
}
