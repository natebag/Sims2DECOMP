// 0x800BB6A8 HouseImpl::Destroy(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x20(31); cmpwi 3,0; beq 0f; li 4,3; bl _s800BB6A8_0; 0:; lwz 3,0x1c(31); li 30,0; stw 30,0x20(31); cmpwi 3,0; beq 1f; li 4,3; bl _s800BB6A8_1; 1:; lwz 3,-21472(13); stw 30,0x1c(31); cmpwi 3,0; beq 2f; li 4,3; bl _s800BB6A8_2; 2:; lwz 11,-21484(13); stw 30,-21472(13); cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,-21484(13); bl _s800BB6A8_3; stw 30,-21484(13); 3:; lwz 3,-21496(13); bl _s800BB6A8_4; stw 30,-21496(13); stw 30,0x14(31); bl _s800BB6A8_5; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BB6A8_0();
extern "C" void _s800BB6A8_1();
extern "C" void _s800BB6A8_2();
extern "C" void _s800BB6A8_3();
extern "C" void _s800BB6A8_4();
extern "C" void _s800BB6A8_5();
extern "C" void f_800BB6A8() {}
