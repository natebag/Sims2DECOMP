// 0x8016FD00 CasSimRendererDynamic::GetIndexes(eBodyPartS2C, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 29,3; mr 27,4; mr 25,5; mr 26,6; bl _s8016FD00_0; li 31,0; mr 24,3; li 4,1; lwz 3,-21476(13); li 30,0; lwz 9,0x0(3); lha 0,0x120(9); lwz 9,0x124(9); add 3,3,0; mtspr 8,9; blrl; mr 28,3; lwz 3,0x0(29); bl _s8016FD00_1; lwz 23,0x84(3); cmplw 31,24; bge 4f; lis 9,-32697; addi 29,29,8; addi 21,9,24012; li 22,0; 0:; lwz 0,0x3c8(21); cmpwi 0,0; beq 1f; stbx 30,25,31; stbx 22,26,31; b 2f; 1:; lwz 3,0x138(29); mr 4,27; mr 5,30; bl _s8016FD00_2; cmpwi 3,1000; beq 3f; stbx 30,25,31; lwz 9,0x0(28); lha 3,0x160(9); lwz 0,0x164(9); add 3,28,3; mtspr 8,0; blrl; mr 4,23; mr 5,27; mr 6,30; bl _s8016FD00_3; stbx 3,26,31; 2:; addi 31,31,1; 3:; addi 0,30,1; rlwinm 30,0,0,24,31; cmplw 30,24; blt 0b; 4:; mr 3,31; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s8016FD00_0();
extern "C" void _s8016FD00_1();
extern "C" void _s8016FD00_2();
extern "C" void _s8016FD00_3();
extern "C" void f_8016FD00() {}
