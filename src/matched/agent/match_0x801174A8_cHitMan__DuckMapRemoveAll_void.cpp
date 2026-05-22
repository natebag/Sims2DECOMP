// 0x801174A8 cHitMan::DuckMapRemoveAll(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 30,3; li 8,0; addi 31,30,64; lwz 9,0x4(31); lwz 11,0x8(9); stw 11,0x8(1); lwz 10,0x4(31); stw 11,0x18(1); stw 10,0x10(1); stw 10,0x20(1); lwz 9,0x4(31); lwz 0,0x8(9); cmpw 11,0; stw 0,0x28(1); bne 0f; lwz 0,0x4(31); stw 0,0x30(1); xor 8,10,0; subfic 9,8,0; adde 8,9,8; 0:; cmpwi 8,0; beq 3f; lwz 0,0x8(31); cmpwi 0,0; beq 5f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s801174A8_0; lwz 9,0x4(31); li 0,0; stw 9,0x8(9); lwz 11,0x4(31); stw 0,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 0,0x8(31); b 5f; 1:; mr 3,9; stw 9,0x40(1); bl _s801174A8_1; lwz 0,0x40(1); stw 3,0x18(1); stw 0,0x38(1); mr 3,0; lwz 5,0x4(31); addi 6,5,12; addi 4,5,4; addi 5,5,8; bl _s801174A8_2; mr. 3,3; beq 2f; li 4,24; bl _s801174A8_3; 2:; lwz 9,0x8(31); addi 9,9,-1; stw 9,0x8(31); 3:; lwz 9,0x18(1); li 11,1; lwz 0,0x20(1); cmpw 9,0; bne 4f; li 11,0; 4:; cmpwi 11,0; bne 1b; 5:; li 0,0; mr 3,30; stw 0,-31776(13); bl _s801174A8_4; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s801174A8_0();
extern "C" void _s801174A8_1();
extern "C" void _s801174A8_2();
extern "C" void _s801174A8_3();
extern "C" void _s801174A8_4();
extern "C" void f_801174A8() {}
