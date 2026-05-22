// 0x8021C06C InteractorModule::PlacementObject::Drop(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x0(31); cmpwi 3,0; beq 1f; bl _s8021C06C_0; cmpwi 3,1; bne 1f; li 30,0; mr 3,31; stw 30,0x0(31); addi 4,31,4; bl _s8021C06C_1; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s8021C06C_2; bl _s8021C06C_3; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,-32543; ori 4,4,43469; bl _s8021C06C_4; addi 11,1,8; li 0,-1; stw 30,0x4(11); li 3,1; stw 0,0x8(1); stw 30,0x28(31); lwz 0,0x4(11); rlwinm 0,0,4,0,27; stw 0,0x4(11); lwz 9,0x8(1); rlwinm 9,9,4,0,27; stw 9,0x8(1); lwz 11,0x8(1); lwz 12,0xc(1); stw 11,0x2c(31); stw 12,0x30(31); b 3f; 1:; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s8021C06C_5; bl _s8021C06C_6; stw 3,-31536(13); 2:; lwz 3,-31536(13); lis 4,28199; ori 4,4,30903; bl _s8021C06C_7; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8021C06C_0();
extern "C" void _s8021C06C_1();
extern "C" void _s8021C06C_2();
extern "C" void _s8021C06C_3();
extern "C" void _s8021C06C_4();
extern "C" void _s8021C06C_5();
extern "C" void _s8021C06C_6();
extern "C" void _s8021C06C_7();
extern "C" void f_8021C06C() {}
