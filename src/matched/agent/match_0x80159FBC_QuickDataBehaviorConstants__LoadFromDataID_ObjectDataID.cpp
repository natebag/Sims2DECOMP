// 0x80159FBC QuickDataBehaviorConstants::LoadFromDataID(ObjectDataID (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; addi 3,30,8; bl _s80159FBC_0; lwz 11,-21508(13); lwz 4,0x0(31); lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x8(3); li 4,0; lwz 3,0x20(9); cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; rlwinm 4,4,4,0,27; lhz 5,0x4(31); add 4,3,4; bl _s80159FBC_1; stw 3,0x18(30); cmpwi 3,0; beq 2f; lwz 3,0x4(3); li 0,0; cmpwi 3,0; beq 1f; lwz 0,-4(3); 1:; sth 0,0x4(30); li 3,1; b 3f; 2:; sth 3,0x4(30); li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80159FBC_0();
extern "C" void _s80159FBC_1();
extern "C" void f_80159FBC() {}
