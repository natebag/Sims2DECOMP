// 0x801F4940 INVTarget::SetOnMsgInvGrabMode(char *) (96B)

namespace InteractorModule {
    struct WallData;
}

class INVTarget {
public:
    char _pad0[132];
    int m_modeIdx;

    void EnterGrabModeNewInteractorApi();
    void EnterWallBuildMode(InteractorModule::WallData* wd, int mode);
    void SetOnMsgInvGrabMode(char* a);
};

extern int gv_INVTarget_state_table[2];

void INVTarget::SetOnMsgInvGrabMode(char* a) {
    int state = gv_INVTarget_state_table[m_modeIdx];
    switch (state) {
        case 0:
        case 2:
            EnterGrabModeNewInteractorApi();
            break;
        case 1:
            EnterWallBuildMode(0, (int)1);
            break;
    }
}
