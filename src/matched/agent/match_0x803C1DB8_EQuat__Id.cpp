// 0x803C1DB8 EQuat::Id(void) (40B)
// Pipeline: swap r9/r11, alias this to r9, then rename EQuat_one lis+lfs from r9 to r10
// ASMPROC_gpr_relabel: swap=9:11
// ASMPROC_this_alias_rN: reg=9 after="lfs 0,"
// ASMPROC_force_reg_at_pos: match="lis 9," pos=0 from_reg=9 to_reg=10
// ASMPROC_force_reg_at_pos: match="lfs 13," pos=1 from_reg=9 to_reg=10

extern float EQuat_zero[3];
extern float EQuat_one[3];

class EQuat {
public:
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    void Id();
};

void EQuat::Id() {
    float zero = EQuat_zero[0];
    float one = EQuat_one[0];
    *(volatile float*)&m_x = zero;
    *(volatile float*)&m_w = one;
    *(volatile float*)&m_z = zero;
    *(volatile float*)&m_y = zero;
}
