// 0x80229690 EInstance::GetVelocity (24b)
// FLAGS: -fno-schedule-insns
extern float g_zeroVelocity[3];  /* 3-elem forces lis+lfs (not sda21) */

struct EVec3 { float x, y, z; };
struct EInstance {
    void GetVelocity(EVec3& v);
};

void EInstance::GetVelocity(EVec3& v) {
    float f = g_zeroVelocity[0];
    v.x = f;
    v.z = f;
    v.y = f;
}
