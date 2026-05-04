// ASMPROC_force_reg_at_pos: match="srawi 10,4,31" pos=0 from_reg=10 to_reg=11
// ASMPROC_force_reg_at_pos: match="subf 0,10,0" pos=1 from_reg=10 to_reg=11
// ASMPROC_force_reg_at_pos: match="mulli 11,0,100" pos=0 from_reg=11 to_reg=0
// ASMPROC_force_reg_at_pos: match="cmpw 0,11,4" pos=1 from_reg=11 to_reg=0
// ASMPROC_swap_operands: match="cmpw 0,0,4" pos=1,2
// ASMPROC_force_reg_at_pos: match="subf 0,10,0" pos=1 from_reg=10 to_reg=11
// ASMPROC_force_reg_at_pos: match="mulli 3,0,400" pos=0 from_reg=3 to_reg=0
// ASMPROC_force_reg_at_pos: match="xor 3,3,11" pos=1 from_reg=3 to_reg=4
// ASMPROC_force_reg_at_pos: match="xor 3,4,11" pos=2 from_reg=11 to_reg=0
// ASMPROC_force_reg_at_pos: match="subfic 0,3,0" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="adde 3,0,3" pos=1 from_reg=0 to_reg=9

struct AptDate {
    bool dateIsYearLeap(int);
};

bool AptDate::dateIsYearLeap(int year) {
    bool result = false;
    if ((year & 3) == 0) {
        if ((year / 100) * 100 != year) {
            result = true;
        } else {
            result = ((year / 400) * 400 == year);
        }
    }
    return result;
}
