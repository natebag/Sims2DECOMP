// FLAGS: -fno-schedule-insns
// 0x8031B418 ERModel::GetCamera(int) (16B)
// mulli r4,r4,88; lwz r3,0x128(3); add r3,r3,r4; blr  -- &m_cameras[i], stride 88
struct ERCamera { char data[88]; };

struct ERModel {
    char pad[0x128];
    ERCamera* m_cameras;    // 0x128
    ERCamera* GetCamera(int i);
};

ERCamera* ERModel::GetCamera(int i) {
    return &m_cameras[i];
}
