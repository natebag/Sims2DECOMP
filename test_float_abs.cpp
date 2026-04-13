#define g_zeroVelocity (*(float*)0x803FE828)
struct EVec3 { float x, y, z; };
void GetVelocity(EVec3& v) {
    v.x = g_zeroVelocity;
    v.z = g_zeroVelocity;
    v.y = g_zeroVelocity;
}
