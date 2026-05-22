// 0x80238608 Emitter::SetState(int, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 9,0x7c(11); cmpwi 9,0; beq 2f; cmpwi 7,5,0; beq cr7,0f; lwz 0,0x50(9); or 0,0,4; b 1f; 0:; lwz 0,0x50(9); andc 0,0,4; 1:; stw 0,0x50(9); andi. 0,4,16384; beq 2f; beq cr7,2f; lwz 9,-26512(13); lwz 0,0x4(11); lwz 3,0x30(9); cmpwi 0,0; beq 2f; mr 4,11; bl _s80238608_0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80238608_0();
extern "C" void f_80238608() {}
