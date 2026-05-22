// 0x800DD268 cXObjectImpl::HierSever(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 31,3; addi 3,1,8; mr 4,31; bl _s800DD268_0; lwz 9,0x14(1); cmpwi 9,0; beq 0f; lwz 0,0x18(1); li 11,0; lwz 9,0x90(9); rlwinm 0,0,5,0,26; add 9,9,0; sth 11,0x4(9); b 1f; 0:; lwz 0,0x8(1); cmpwi 0,0; beq 1f; addi 30,1,32; lwz 5,0x1c(1); addi 4,1,12; mr 3,30; bl _s800DD268_1; lwz 11,-21484(13); mr 4,30; li 5,0; lwz 9,0x0(11); lha 3,0x258(9); lwz 0,0x25c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; li 4,2; bl _s800DD268_2; 1:; addi 30,31,40; li 4,26; li 5,0; mr 3,30; bl _s800DD268_3; mr 3,30; li 4,14; li 5,-1; bl _s800DD268_4; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s800DD268_0();
extern "C" void _s800DD268_1();
extern "C" void _s800DD268_2();
extern "C" void _s800DD268_3();
extern "C" void _s800DD268_4();
extern "C" void f_800DD268() {}
