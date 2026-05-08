// 0x802041CC (84B) InteractorModule::DirectInteractor::GetDesiredAnimState(bool, EVec2)
// Returns anim state code based on stick magnitude vs two thresholds.
// Returns 9 if arg0 (override) is true, or if magnitude is below lower threshold.
// Returns 14 if magnitude exceeds upper threshold, else 13.
//
// goto restructure: produces backward bso (REL14-masked, DOL tail-merge to shared ret9 block)
// lfs swap: DOL loads y(+4) before x(+0); GCC hardwires memory-order (lower addr first)
// bclr 12,1 (bgtlr): inject cror 3,2,0 before + change to bclr 4,3 (bnslr)
//   DOL uses cror SO=LT|EQ + bnslr idiom instead of plain bgtlr
//
// ASMPROC_replace_insn: match="lfs 0,0(5)" replacement="lfs 0,4(5)"
// ASMPROC_replace_insn: match="lfs 13,4(5)" replacement="lfs 13,0(5)"
// ASMPROC_nop_before: match="bclr 12,1"
// ASMPROC_replace_insn: match="nop" replacement="cror 3,2,0"
// ASMPROC_replace_insn: match="bclr 12,1" replacement="bclr 4,3"

extern char k_diInteractor_animThresh1[16];
extern char k_diInteractor_animThresh2[16];

struct EVec2 {
    float x;
    float y;
};

namespace InteractorModule {

class DirectInteractor {
public:
    int GetDesiredAnimState(bool arg0, const EVec2& vec);
};

int DirectInteractor::GetDesiredAnimState(bool arg0, const EVec2& vec) {
    if (!arg0) goto not_arg0;
ret9:
    return 9;
not_arg0:
    float mag2 = vec.y * vec.y + vec.x * vec.x;
    if (mag2 <= *(float*)k_diInteractor_animThresh1) goto ret9;
    if (mag2 > *(float*)k_diInteractor_animThresh2) return 14;
    return 13;
}

}
