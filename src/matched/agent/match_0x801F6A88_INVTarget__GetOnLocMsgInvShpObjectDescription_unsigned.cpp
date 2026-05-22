// 0x801F6A88 INVTarget::GetOnLocMsgInvShpObjectDescription(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,4; addi 5,1,8; lbz 4,0x3251(3); addi 6,1,16; bl _s801F6A88_0; lwz 0,0x10(1); cmpwi 0,11; bgt 0f; cmpwi 0,9; bge 2f; 0:; cmplwi 0,14; bgt 2f; lwz 4,0x8(1); addi 3,1,20; crxor 6,6,6; bl _s801F6A88_1; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,31; bl _s801F6A88_2; 2:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801F6A88_0();
extern "C" void _s801F6A88_1();
extern "C" void _s801F6A88_2();
extern "C" void f_801F6A88() {}
