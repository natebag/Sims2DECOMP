// 0x80286168 AptArray::toString(EAStringC (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 28,4; addi 29,1,8; mr 30,3; lis 4,-32704; addi 4,4,15160; mr 25,5; mr 3,29; bl _s80286168_0; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80286168_1; 0:; lwz 4,0x8(1); stw 4,0x0(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80286168_2; 1:; lwz 0,0x2c(30); li 31,0; cmpw 31,0; bge 5f; lis 27,-32700; mr 26,29; addi 24,27,-6476; li 29,0; 2:; lwz 9,0x24(30); lwzx 3,29,9; cmpwi 3,0; beq 3f; lhz 9,-6476(27); mr 4,26; stw 24,0x8(1); addi 9,9,1; sth 9,-6476(27); bl _s80286168_3; mr 4,26; mr 3,28; bl _s80286168_4; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80286168_5; 3:; lwz 9,0x2c(30); addi 9,9,-1; cmpw 31,9; bge 4f; mr 3,28; mr 4,25; bl _s80286168_6; 4:; lwz 0,0x2c(30); addi 31,31,1; addi 29,29,4; cmpw 31,0; blt 2b; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s80286168_0();
extern "C" void _s80286168_1();
extern "C" void _s80286168_2();
extern "C" void _s80286168_3();
extern "C" void _s80286168_4();
extern "C" void _s80286168_5();
extern "C" void _s80286168_6();
extern "C" void f_80286168() {}
