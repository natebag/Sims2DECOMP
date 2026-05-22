// 0x8009F8FC BString::compare(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 31,4; mr 30,5; bl _s8009F8FC_0; subf 28,30,3; cmpwi 31,0; beq 0f; mr 3,31; bl _s8009F8FC_1; mr 7,3; b 1f; 0:; li 7,0; 1:; mr 3,29; mr 4,30; mr 5,31; mr 6,28; bl _s8009F8FC_2; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009F8FC_0();
extern "C" void _s8009F8FC_1();
extern "C" void _s8009F8FC_2();
extern "C" void f_8009F8FC() {}
