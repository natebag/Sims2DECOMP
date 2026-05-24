// 0x8021E6E0 InteractorModule::SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3* pos) (76 B)
// ASMPROC_region_gpr_relabel: start_anchor="lwz 0,0(9)" end_anchor="stw 10,8(8)" rename="0:11,11:10,10:0"
// ASMPROC_swap_adj: a=stw b=stw which=last
namespace InteractorModule {
struct EVec3 { int x, y, z; };
extern void _CutCameraToPos_s8021E6E0(void* cam, EVec3* pos);
struct SimInteractor {
    int m_pad0;
    void* m_cameraTarget;
    int m_cursorPos[3];
    char m_pad1[0x178];
    int m_immediateCut;
    void ImmediatelyCutCursorAndCameraToPos(EVec3* pos);
};
void SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3* pos) {
    m_immediateCut = 1;
    int* cp = m_cursorPos;
    int x = pos->x;
    int y = pos->y;
    int z = pos->z;
    cp[0] = x;
    cp[2] = z;
    cp[1] = y;
    _CutCameraToPos_s8021E6E0(m_cameraTarget, pos);
}
}
