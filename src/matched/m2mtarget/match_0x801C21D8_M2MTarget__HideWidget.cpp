/* M2MTarget::HideWidget(void) at 0x801C21D8 (160b) */

extern const char gReflowId1[];
extern const char gReflowId2[];
extern const char gReflowId3[];

struct UIReflow {
    void OpenReflowBlock();
    void Reflow_Id(const char *id, int val);
    void Reflow_Visibility(int vis);
    void SubmitReflowBlock();
};

struct M2MTarget {
    char pad_00[0x120];
    UIReflow m_reflow;
    char pad_xxx[0x44];
    int m_widgetVisible;

    void HideWidget();
};

void M2MTarget::HideWidget() {
    m_widgetVisible = 0;
    m_reflow.OpenReflowBlock();
    m_reflow.Reflow_Id(gReflowId1, 0);
    m_reflow.Reflow_Visibility(0);
    m_reflow.Reflow_Id(gReflowId2, 0);
    m_reflow.Reflow_Visibility(0);
    m_reflow.Reflow_Id(gReflowId3, 0);
    m_reflow.Reflow_Visibility(0);
    m_reflow.SubmitReflowBlock();
}
