// 0x802AA4E4 AptNativeHash::Expand(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 31,3; addi 30,1,8; lwz 4,0x0(31); mr 3,30; li 29,0; rlwinm 4,4,1,0,30; bl _s802AA4E4_0; lwz 4,0x8(1); lwz 3,-23020(13); rlwinm 4,4,3,0,28; bl _s802AA4E4_1; lwz 5,0x8(1); li 4,0; stw 3,0x4(30); rlwinm 5,5,3,0,28; bl _s802AA4E4_2; lwz 0,0x0(31); cmpw 29,0; bge 3f; lis 9,-32700; li 30,0; addi 28,9,-6476; 0:; lwz 9,0x4(31); li 11,1; lwzx 0,9,30; add 4,9,30; cmpwi 0,0; bne 1f; li 11,0; 1:; cmpwi 11,0; beq 2f; cmpw 0,28; beq 2f; lwz 5,0x4(4); addi 3,1,8; bl _s802AA4E4_3; 2:; lwz 0,0x0(31); addi 29,29,1; addi 30,30,8; cmpw 29,0; blt 0b; 3:; lwz 9,0xc(1); addi 3,1,8; lwz 0,0x8(1); lwz 10,0x4(31); lwz 11,0x0(31); stw 0,0x0(31); stw 9,0x4(31); stw 10,0xc(1); stw 11,0x8(1); bl _s802AA4E4_4; addi 3,1,8; li 4,2; bl _s802AA4E4_5; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s802AA4E4_0();
extern "C" void _s802AA4E4_1();
extern "C" void _s802AA4E4_2();
extern "C" void _s802AA4E4_3();
extern "C" void _s802AA4E4_4();
extern "C" void _s802AA4E4_5();
extern "C" void f_802AA4E4() {}
