/* InteractorModule::WallManipulator::AdjustCursorPosition(void) at 0x80221394 (44B) */

struct EVec3_ACP { float x, y, z; };

namespace InteractorModule {
    enum IMSnapType {};
    extern void SnapPositionToTile(EVec3_ACP&, EVec3_ACP&, IMSnapType);

    struct WallManipulator_ACP {
        char pad[0x08];
        EVec3_ACP m_posA;
        char pad2[0x0C];
        EVec3_ACP m_posB;
        void AdjustCursorPosition();
    };
}

void InteractorModule::WallManipulator_ACP::AdjustCursorPosition() {
    InteractorModule::SnapPositionToTile(m_posA, m_posB, (IMSnapType)2);
}
