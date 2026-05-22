// 0x8009630C StateMachine::PopStatus(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); addi 9,3,100; lwz 11,0x64(3); lwz 10,0x4(9); addi 6,1,8; lwz 8,0xc(9); addi 7,3,84; lwz 0,0x8(9); cmpw 11,10; stw 11,0x8(1); stw 0,0x10(1); stw 10,0xc(1); stw 8,0x14(1); bne 0f; addi 0,8,-4; stw 0,0x14(1); lwz 9,-4(8); addi 11,9,128; stw 9,0xc(1); stw 11,0x10(1); lwz 0,0x8(6); stw 0,0x8(1); 0:; lwz 9,0x8(1); addi 11,3,60; addi 0,9,-4; stw 0,0x8(1); lwz 31,-4(9); lwz 0,0x0(31); lwz 9,0x4(31); lwz 10,0x8(31); lwz 8,0xc(31); stw 0,0x3c(3); stw 9,0x4(11); stw 10,0x8(11); stw 8,0xc(11); lwz 0,0x10(31); lwz 9,0x14(31); stw 0,0x10(11); stw 9,0x14(11); lwz 9,0x10(7); lwz 0,0x14(7); cmpw 9,0; beq 1f; addi 0,9,-4; stw 0,0x10(7); b 2f; 1:; mr 3,7; bl _s8009630C_0; 2:; cmpwi 31,0; beq 3f; mr 3,31; bl _s8009630C_1; 3:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s8009630C_0();
extern "C" void _s8009630C_1();
extern "C" void f_8009630C() {}
