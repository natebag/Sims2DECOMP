/* RMDTarget::StartShowTween(void) at 0x801E014C (224b) */

extern const char gRMDReflowId[];
extern const char gRMDTweenId[];
extern const char gRMDTweenName2[];

struct UIReflow {
    char pad[24];
    UIReflow();
    ~UIReflow();
    void OpenReflowBlock();
    void Reflow_Id(const char *id, int val);
    void Reflow_Visibility(int vis);
    void Reflow_Alpha(unsigned int alpha);
    void SubmitReflowBlock();
    void OpenTweenBlock(const char *id, int dur, int delay, const char *name, int mode);
    void Tween_Alpha(unsigned int alpha);
    void SubmitTweenBlock();
};

struct RMDTarget {
    char pad_00[0x88];
    int m_state;
};

void RMDTarget_StartShowTween(RMDTarget *self) {
    if (self->m_state != 0) return;
    self->m_state = 1;
    UIReflow reflow;
    reflow.OpenReflowBlock();
    reflow.Reflow_Id(gRMDTweenId, 0);
    reflow.Reflow_Alpha(0);
    reflow.Reflow_Visibility(1);
    reflow.Reflow_Id(gRMDReflowId, 0);
    reflow.Reflow_Visibility(0);
    reflow.SubmitReflowBlock();
    reflow.OpenTweenBlock(gRMDTweenId, 250, 0, gRMDTweenName2, 0);
    reflow.Tween_Alpha(255);
    reflow.SubmitTweenBlock();
}
