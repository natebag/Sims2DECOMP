// 0x8001A328 ESimsCam::SetActiveNoiseSetting(CameraNoiseSetting) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 11,0x4a8(31); cmpw 4,11; beq 3f; cmpwi 4,-1; beq 0f; lis 9,-32697; lwz 0,0x5c74(9); cmpwi 0,0; beq 1f; 0:; li 0,-1; stw 0,0x4a8(31); b 3f; 1:; cmpwi 11,-1; rlwinm 8,4,2,0,29; beq 2f; lwz 9,0x0(31); rlwinm 11,11,2,0,29; addi 9,9,392; lwzx 10,9,11; lwzx 0,9,8; cmpw 0,10; blt 3f; 2:; lwz 9,0x0(31); stw 4,0x4a8(31); addi 9,9,420; lwzx 0,9,8; cmpwi 0,0; beq 3f; addi 29,31,1196; lwzx 0,29,8; cmpwi 0,0; beq 3f; addi 30,31,1224; li 4,1; mr 3,30; bl _s8001A328_0; lwz 0,0x4a8(31); rlwinm 0,0,2,0,29; lwzx 9,29,0; cmpw 3,9; beq 3f; mr 3,30; bl _s8001A328_1; lwz 0,0x4a8(31); lis 9,-32707; lfs f1,-7112(9); mr 3,30; rlwinm 0,0,2,0,29; li 4,1; lwzx 5,29,0; li 6,-1; li 7,0; bl _s8001A328_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001A328_0();
extern "C" void _s8001A328_1();
extern "C" void _s8001A328_2();
extern "C" void f_8001A328() {}
