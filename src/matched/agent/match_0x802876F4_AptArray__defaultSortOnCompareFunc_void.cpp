// 0x802876F4 AptArray::defaultSortOnCompareFunc(void (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lwz 31,0x0(3); li 11,0; lwz 30,0x0(4); lwz 9,0x0(31); rlwinm 0,9,0,25,31; cmpwi 0,27; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 2f; lwz 9,0x0(30); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,27; bne 1f; rlwinm 11,9,5,31,31; 1:; cmpwi 11,0; beq 2f; li 0,0; addi 3,31,12; stw 0,0xc(1); addi 4,13,-22980; stw 0,0x8(1); bl _s802876F4_0; cmpwi 3,0; stw 3,0x8(1); beq 5f; addi 3,30,12; addi 4,13,-22980; bl _s802876F4_1; cmpwi 3,0; stw 3,0xc(1); beq 5f; addi 3,1,8; addi 4,1,12; bl _s802876F4_2; b 6f; 2:; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 3f; rlwinm 11,9,5,31,31; 3:; cmpwi 11,0; beq 5f; lwz 9,0x0(30); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 4f; rlwinm 11,9,5,31,31; 4:; cmpwi 11,0; beq 5f; lwz 3,-22980(13); li 0,0; stw 0,0x14(1); stw 0,0x10(1); addi 3,3,8; bl _s802876F4_3; mr 4,3; mr 3,31; bl _s802876F4_4; lwz 9,-22980(13); stw 3,0x10(1); addi 3,9,8; bl _s802876F4_5; mr 4,3; mr 3,30; bl _s802876F4_6; stw 3,0x14(1); addi 4,1,20; addi 3,1,16; bl _s802876F4_7; b 6f; 5:; li 3,0; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s802876F4_0();
extern "C" void _s802876F4_1();
extern "C" void _s802876F4_2();
extern "C" void _s802876F4_3();
extern "C" void _s802876F4_4();
extern "C" void _s802876F4_5();
extern "C" void _s802876F4_6();
extern "C" void _s802876F4_7();
extern "C" void f_802876F4() {}
