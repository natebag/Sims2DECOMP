// 0x80111194 ObjSelector::GetInitTreeVersion(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x74(31); cmpwi 0,-1; bne 0f; bl _s80111194_0; lwz 9,0x0(3); li 4,0; lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; mr 4,3; lwz 3,0xc(31); bl _s80111194_1; stw 3,0x74(31); 0:; lwz 3,0x74(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80111194_0();
extern "C" void _s80111194_1();
extern "C" void f_80111194() {}
