// 0x800799CC CUnlockDisplayObject::SetMultiColorIndex(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x74(31); stw 30,0x18(31); cmpwi 0,0; beq 0f; lwz 3,0x1c(31); lwz 9,0x0(3); lha 0,0x118(9); lwz 9,0x11c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 11,0x1c(31); mr 4,30; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; li 0,-1; stw 0,0x18(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_800799CC() {}
