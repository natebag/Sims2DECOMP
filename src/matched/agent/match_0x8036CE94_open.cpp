// 0x8036CE94 open (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 30,0x70(1); stw 0,0x7c(1); mr 30,3; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; mr 31,4; andi. 0,31,512; beq 1f; mr 3,30; li 4,0; bl _s8036CE94_0; cmpwi 3,-1; beq 1f; bl _s8036CE94_1; cmpwi 3,0; li 3,-1; bne 2f; 1:; mr 3,30; mr 4,31; li 5,0; bl _s8036CE94_2; 2:; lwz 0,0x7c(1); mtspr 8,0; lmw 30,0x70(1); addi 1,1,120"
extern "C" void _s8036CE94_0();
extern "C" void _s8036CE94_1();
extern "C" void _s8036CE94_2();
extern "C" void f_8036CE94() {}
