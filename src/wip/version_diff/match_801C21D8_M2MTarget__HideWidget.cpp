/* M2MTarget::HideWidget(void) at 0x801C21D8 (160B) */

extern char s_widgetId1[];
extern char s_widgetId2[];
extern char s_widgetId3[];

struct UIReflow {
    void OpenReflowBlock();
    void Reflow_Id(char*, int);
    void Reflow_Visibility(int);
    void SubmitReflowBlock();
};

struct M2MTarget {
    char pad_000[0x120];
    UIReflow m_reflow;
    char pad_XXX[0x168 - 0x120 - sizeof(UIReflow)];
    int m_field168;

    void HideWidget();
};

void M2MTarget::HideWidget() {
    m_field168 = 0;
    m_reflow.OpenReflowBlock();
    m_reflow.Reflow_Id(s_widgetId1, 0);
    m_reflow.Reflow_Visibility(0);
    m_reflow.Reflow_Id(s_widgetId2, 0);
    m_reflow.Reflow_Visibility(0);
    m_reflow.Reflow_Id(s_widgetId3, 0);
    m_reflow.Reflow_Visibility(0);
    m_reflow.SubmitReflowBlock();
}
