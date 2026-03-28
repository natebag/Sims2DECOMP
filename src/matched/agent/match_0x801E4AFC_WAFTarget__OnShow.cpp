/* WAFTarget::OnShow(void) at 0x801E4AFC (192b) */

extern const char gWAFReflowIdA[];
extern const char gWAFReflowIdB[];
extern const char gWAFReflowIdC[];

struct UIReflow {
    void OpenReflowBlock();
    void Reflow_Id(const char *id, int val);
    void Reflow_Visibility(int vis);
    void SubmitReflowBlock();
};

struct WAFTarget {
    char pad_00[0x94];
    int m_pField94;
    char pad_98[0x1B8];
    UIReflow m_reflow;

    void OnShow();
    void UpdateAspirationMeter();
};

void WAFTarget::OnShow() {
    m_reflow.OpenReflowBlock();
    m_reflow.Reflow_Id(gWAFReflowIdA, m_pField94);
    m_reflow.Reflow_Visibility(1);
    m_reflow.Reflow_Id(gWAFReflowIdB, m_pField94);
    m_reflow.Reflow_Visibility(1);
    m_reflow.Reflow_Id(gWAFReflowIdA, m_pField94);
    m_reflow.Reflow_Visibility(1);
    m_reflow.Reflow_Id(gWAFReflowIdC, m_pField94);
    m_reflow.Reflow_Visibility(1);
    m_reflow.SubmitReflowBlock();
    UpdateAspirationMeter();
}
