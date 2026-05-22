// 0x800608DC SAnimator2::GetTurnRate(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x18(3); lis 9,-32707; lfs f1,0x4784(9); cmpwi 0,3; beqlr; lbz 0,0x5f8(3); cmpwi 0,2; beqlr; lwz 9,0x2c(3); cmpwi 9,12; bne 1f; 0:; lis 9,-32707; lfs f1,0x4788(9); blr; 1:; addi 0,9,-13; cmplwi 0,1; ble 0b; lfs f1,0x98(3)"
extern "C" float f_800608DC() {}
