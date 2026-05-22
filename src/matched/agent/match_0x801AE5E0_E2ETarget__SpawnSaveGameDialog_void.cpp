// 0x801AE5E0 E2ETarget::SpawnSaveGameDialog(void) (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); mr 31,3; li 0,2; lis 29,-32697; lis 5,-32705; addi 4,29,24012; stw 0,0x16c(31); addi 5,5,-1344; addi 3,1,24; crxor 6,6,6; bl _s801AE5E0_0; addi 30,31,412; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s801AE5E0_1; addi 30,31,416; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-1340; addi 3,1,28; crxor 6,6,6; bl _s801AE5E0_2; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s801AE5E0_3; addi 30,31,404; lis 5,-32705; addi 4,29,24012; addi 5,5,-1300; addi 3,1,32; crxor 6,6,6; bl _s801AE5E0_4; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s801AE5E0_5; lis 4,-32705; addi 3,31,408; addi 4,4,-8284; bl _s801AE5E0_6; lis 9,-32705; li 0,0; addi 9,9,-1264; stw 0,0x180(31); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; addi 4,1,40; addi 30,11,27868; stw 7,0x28(1); stw 8,0x2c(1); cmpwi 31,0; stw 31,0x10(1); beq 3f; addi 3,1,8; li 5,8; bl _s801AE5E0_7; b 4f; 3:; stw 31,0x8(1); 4:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 5,0x8(1); addi 9,9,-1960; lwz 4,0x4(11); lwz 3,0x8(11); addi 10,31,444; lwz 8,0xc(11); addi 0,31,364; lwz 6,0x0(9); lwz 7,0x4(9); mr 29,11; stw 5,0x1bc(31); lis 9,-32709; stw 8,0xc(10); addi 28,9,14552; stw 4,0x4(10); mr 30,0; stw 3,0x8(10); addi 9,1,48; cmpwi 0,0; stw 6,0x30(1); stw 7,0x34(1); stw 0,0x10(1); beq 5f; mr 4,9; mr 3,29; li 5,8; bl _s801AE5E0_8; b 6f; 5:; stw 30,0x8(1); 6:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-1960; lwz 5,0x8(29); addi 11,31,460; lwz 10,0x4(29); addi 4,1,56; lwz 0,0xc(29); cmpwi 30,0; stw 6,0x1cc(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,14552; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 30,0x10(1); beq 7f; mr 3,29; li 5,8; bl _s801AE5E0_9; b 8f; 7:; stw 30,0x8(1); 8:; stw 28,0x14(1); addi 9,31,476; lwz 8,0x8(1); mr 3,30; lwz 0,0xc(29); lwz 11,0x4(29); lwz 10,0x8(29); stw 8,0x1dc(31); stw 0,0xc(9); stw 11,0x4(9); stw 10,0x8(9); bl _s801AE5E0_10; lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"
extern "C" void _s801AE5E0_0();
extern "C" void _s801AE5E0_1();
extern "C" void _s801AE5E0_2();
extern "C" void _s801AE5E0_3();
extern "C" void _s801AE5E0_4();
extern "C" void _s801AE5E0_5();
extern "C" void _s801AE5E0_6();
extern "C" void _s801AE5E0_7();
extern "C" void _s801AE5E0_8();
extern "C" void _s801AE5E0_9();
extern "C" void _s801AE5E0_10();
extern "C" void f_801AE5E0() {}
