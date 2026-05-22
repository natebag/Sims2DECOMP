// 0x8031A3C4 ERModel::CleanMorphTargets(bool) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; li 31,0; 0:; mr 4,31; mr 3,30; bl _s8031A3C4_0; addi 31,31,1; cmpwi 31,11; ble 0b; cmpwi 29,0; bne 1f; li 0,1; stw 0,0xfc(30); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031A3C4_0();
extern "C" void f_8031A3C4() {}
