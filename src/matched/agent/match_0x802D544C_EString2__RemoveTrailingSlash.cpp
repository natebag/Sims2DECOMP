// 0x802D544C EString2::RemoveTrailingSlash() (120B)
// ASMPROC_swap_adj: a=addi b=addi which=first
// ASMPROC_force_reg_at_pos: match="addi 30,1,8" pos=0 from_reg=30 to_reg=3
// ASMPROC_force_reg_at_pos: match="mr 3,30" pos=0 from_reg=3 to_reg=30
// ASMPROC_force_reg_at_pos: match="mr 30,30" pos=1 from_reg=30 to_reg=3
// ASMPROC_swap_adj: a=mr b=mr which=first
// ASMPROC_swap_adj: a=addi b=mr which=first
typedef unsigned short wchar_t_u;

struct EString2_RTS {
    wchar_t_u *m_str;
    int GetLength() const;
    void RemoveTrailingSlash();
};

extern void RTS_Left(EString2_RTS*, const EString2_RTS*, int);
extern void RTS_Assign(EString2_RTS*, wchar_t_u*);
extern void RTS_Deallocate(EString2_RTS*, wchar_t_u*);

void EString2_RTS::RemoveTrailingSlash() {
    int len = GetLength();
    if (len > 3) {
        if (m_str[len - 1] == '\\') {
            EString2_RTS tmp;
            RTS_Left(&tmp, this, len - 1);
            RTS_Assign(this, tmp.m_str);
            RTS_Deallocate(&tmp, tmp.m_str);
        }
    }
}
