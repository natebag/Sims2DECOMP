// 0x8020415C (112B) InteractorModule::DirectInteractor::ParseControls(void)
// Right-stick section: DOL loads m_rightX before lis (scheduler hoist reversal)
// DOL uses bclr 4,0 (bnlr) for >= returns; GCC emits cror 3,2,1 + bclr 12,3 (bsolr)
//
// ASMPROC_swap_adj: a=lis b=lfs
// ASMPROC_remove_mr: match="cror 3,2,1" assert_op=""
// ASMPROC_replace_insn: match="bclr 12,3" replacement="bclr 4,0"
// ASMPROC_remove_mr: match="cror 3,2,1" assert_op=""
// ASMPROC_replace_insn: match="bclr 12,3" replacement="bclr 4,0"

extern char gControlDeadZone[16];

namespace InteractorModule {

class DirectInteractor {
public:
    char _pad0[0x34];
    float m_leftX;
    float m_leftY;
    float m_rightX;
    float m_rightY;
    int m_leftActive;
    int m_rightActive;

    void ParseControls(void);
};

void DirectInteractor::ParseControls(void) {
    m_leftActive = 0;
    m_rightActive = 0;
    float threshold = *(float*)gControlDeadZone;
    if (__builtin_fabsf(m_leftX) < threshold) {
        if (__builtin_fabsf(m_leftY) < threshold) {
            m_leftActive = 1;
        }
    }
    float threshold2 = *(float*)gControlDeadZone;
    if (__builtin_fabsf(m_rightX) >= threshold2) return;
    if (__builtin_fabsf(m_rightY) >= threshold2) return;
    m_rightActive = 1;
}

}
