// 0x8032D634 ENgcAudioSampleManager::heapFree(unsigned (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; stw 31,0x8(1); li 4,-1; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; mr 4,30; mr 3,31; bl _s8032D634_0; mr 30,3; lwz 4,0x4(30); mr 3,31; bl _s8032D634_1; cmpwi 3,0; beq 3f; lwz 11,0x4(30); lwz 0,0x4(11); stw 0,0x4(30); lwz 9,0x4(11); stw 30,0x0(9); lwz 9,0x8(11); cmpwi 9,0; beq 0f; lwz 0,0xc(11); stw 0,0xc(9); b 1f; 0:; lwz 0,0xc(11); stw 0,0xd24(31); 1:; lwz 9,0xc(11); cmpwi 9,0; beq 2f; lwz 0,0x8(11); stw 0,0x8(9); 2:; lis 9,-32692; addi 9,9,18184; lwz 0,0x8(9); stw 0,0x0(11); stw 11,0x8(9); 3:; lwz 4,0x0(30); mr 3,31; bl _s8032D634_2; cmpwi 3,0; beq 4f; lwz 10,0x0(30); lis 11,-32692; lwz 0,0x4(30); addi 11,11,18184; stw 0,0x4(10); lwz 9,0x4(30); stw 10,0x0(9); lwz 0,0x8(11); stw 0,0x0(30); stw 30,0x8(11); mr 30,10; b 6f; 4:; lwz 9,0xd24(31); stw 9,0xc(30); cmpwi 9,0; beq 5f; stw 30,0x8(9); 5:; stw 30,0xd24(31); 6:; mr 3,31; mr 4,30; bl _s8032D634_3; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8032D634_0();
extern "C" void _s8032D634_1();
extern "C" void _s8032D634_2();
extern "C" void _s8032D634_3();
extern "C" void f_8032D634() {}
