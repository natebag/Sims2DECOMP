// 0x802DAF78 EA::Allocator::GeneralAllocator::ValidateAddress(void (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 31,4; lwz 3,0x4fc(30); mr 29,5; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DAF78_0; 0:; mr 3,30; mr 4,31; bl _s802DAF78_1; mr. 3,3; beq 8f; lwz 3,0x0(3); lwz 10,0x8(1); lwz 0,0x4(3); rlwinm 0,0,0,0,28; add 11,3,0; b 2f; 1:; lwz 0,0x4(11); mr 3,11; rlwinm 0,0,0,0,28; add 11,11,0; 2:; cmplw 11,31; bge 3f; cmpw 11,3; bne 1b; 3:; lwz 9,0x4(3); rlwinm 9,9,0,0,28; add 9,3,9; lwz 0,0x4(9); andi. 9,0,1; beq 8f; addi 3,3,8; cmpwi 29,0; beq 5f; xor 31,31,3; subfic 0,31,0; adde 31,0,31; cmpwi 10,0; beq 4f; mr 3,10; bl _s802DAF78_2; 4:; mr 3,31; b 10f; 5:; cmplw 31,3; li 30,0; blt 6f; subfc 30,11,31; subfe 30,30,30; neg 30,30; 6:; cmpwi 10,0; beq 7f; mr 3,10; bl _s802DAF78_3; 7:; mr 3,30; b 10f; 8:; lwz 3,0x8(1); cmpwi 3,0; beq 9f; bl _s802DAF78_4; 9:; li 3,0; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802DAF78_0();
extern "C" void _s802DAF78_1();
extern "C" void _s802DAF78_2();
extern "C" void _s802DAF78_3();
extern "C" void _s802DAF78_4();
extern "C" void f_802DAF78() {}
