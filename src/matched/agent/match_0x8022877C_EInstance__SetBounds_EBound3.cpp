// 0x8022877C EInstance::SetBounds(EBound3 (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 6,3; mr 5,4; lwz 3,0x4(6); cmpwi 3,0; beq 0f; mr 4,6; bl _s8022877C_0; b 1f; 0:; lwz 11,0x0(5); addi 9,6,60; lwz 0,0x8(5); addi 10,5,12; lwz 8,0x4(5); addi 7,6,72; stw 11,0x3c(6); stw 0,0x8(9); stw 8,0x4(9); lwz 0,0xc(5); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0x48(6); stw 9,0x8(7); stw 11,0x4(7); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8022877C_0();
extern "C" void f_8022877C() {}
