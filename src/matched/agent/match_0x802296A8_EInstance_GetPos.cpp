// 0x802296A8 EInstance::GetPos (24b)
// FLAGS: -fno-schedule-insns
extern float g_zeroPos[3];  /* 3-elem forces lis+lfs (not sda21) */

struct EVec3 { float x, y, z; };
struct EInstance {
    void GetPos(EVec3& v);
};

void EInstance::GetPos(EVec3& v) {
    float f = g_zeroPos[0];
    v.x = f;
    v.z = f;
    v.y = f;
}
