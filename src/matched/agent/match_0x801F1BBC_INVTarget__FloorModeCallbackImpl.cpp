/* INVTarget::FloorModeCallbackImpl(InteractorModule::FloorPainter::CallbackData *) at 0x801F1BBC (144b) */

struct CallbackData {
    int m_type;
    char pad_04[0x0C];
    int m_value;
};

struct INVTarget {
    char pad_00[0x32E8];
    int m_floorValue;

    void FloorModeCallbackImpl(CallbackData *data);
    void ExitFloorTilingMode(int flag);
    void EnterWallBuildMode(int wallData, int mode);
    void SetInvBldItemCount();
};

void INVTarget::FloorModeCallbackImpl(CallbackData *data) {
    int type = data->m_type;
    switch (type) {
    case 3:
        ExitFloorTilingMode(1);
        break;
    case 4:
        ExitFloorTilingMode(0);
        EnterWallBuildMode(0, 1);
        break;
    case 5:
        m_floorValue = data->m_value;
        SetInvBldItemCount();
        break;
    }
}
