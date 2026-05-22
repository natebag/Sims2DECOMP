// 0x8015A2F0 IFFBehaviorConstants::LoadFromDataID(ObjectDataID (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; addi 3,29,8; bl _s8015A2F0_0; lwz 11,-21508(13); lwz 4,0x0(30); lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; lis 4,16963; lwz 9,0xc(31); ori 4,4,20302; lha 5,0x4(30); li 6,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; mr. 5,3; li 3,0; beq 0f; mr 3,29; mr 4,31; bl _s8015A2F0_1; li 3,1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015A2F0_0();
extern "C" void _s8015A2F0_1();
extern "C" void f_8015A2F0() {}
