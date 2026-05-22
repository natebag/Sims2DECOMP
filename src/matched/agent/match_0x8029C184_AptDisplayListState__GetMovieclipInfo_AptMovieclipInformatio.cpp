// 0x8029C184 AptDisplayListState::GetMovieclipInfo(AptMovieclipInformation (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x0(3); mr 30,4; cmpwi 31,0; beq 1f; 0:; mr 3,31; mr 4,30; bl _s8029C184_0; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8029C184_0();
extern "C" void f_8029C184() {}
