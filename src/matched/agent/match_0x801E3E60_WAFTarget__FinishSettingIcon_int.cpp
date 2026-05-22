// 0x801E3E60 WAFTarget::FinishSettingIcon(int) (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 28,4; lis 9,-32705; mulli 31,28,60; mr 30,3; lfs f0,0x6468(9); addi 29,30,592; addi 9,30,188; mr 3,29; addi 26,30,208; addi 25,30,220; stfsx f0,9,31; li 27,0; bl _s801E3E60_0; addi 9,30,196; lwz 5,0x94(30); lwzx 4,9,31; mr 3,29; bl _s801E3E60_1; lwzx 0,26,31; lis 9,-32700; addi 9,9,-25216; mr 3,29; rlwinm 0,0,2,0,29; lwzx 4,9,0; bl _s801E3E60_2; addi 9,30,200; lwz 5,0x94(30); lwzx 4,9,31; mr 3,29; bl _s801E3E60_3; mr 3,29; li 4,1; bl _s801E3E60_4; addi 9,30,204; lwz 5,0x94(30); lwzx 4,9,31; mr 3,29; bl _s801E3E60_5; li 4,1; mr 3,29; bl _s801E3E60_6; lis 4,-32705; addi 3,1,8; mr 5,28; addi 4,4,25672; crxor 6,6,6; bl _s801E3E60_7; lwz 5,0x94(30); addi 4,1,8; mr 3,29; bl _s801E3E60_8; mr 3,29; li 4,1; bl _s801E3E60_9; mr 3,29; bl _s801E3E60_10; addi 8,30,176; addi 11,30,168; lwzx 9,8,31; addi 10,30,180; addi 30,30,172; stwx 9,11,31; lwzx 0,10,31; stwx 0,30,31; stwx 27,8,31; stwx 27,10,31; lwzx 3,25,31; cmpwi 3,0; beq 0f; lwzx 0,26,31; cmpwi 0,1; beq 0f; mr 4,28; bl _s801E3E60_11; stwx 27,25,31; 0:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s801E3E60_0();
extern "C" void _s801E3E60_1();
extern "C" void _s801E3E60_2();
extern "C" void _s801E3E60_3();
extern "C" void _s801E3E60_4();
extern "C" void _s801E3E60_5();
extern "C" void _s801E3E60_6();
extern "C" void _s801E3E60_7();
extern "C" void _s801E3E60_8();
extern "C" void _s801E3E60_9();
extern "C" void _s801E3E60_10();
extern "C" void _s801E3E60_11();
extern "C" void f_801E3E60() {}
