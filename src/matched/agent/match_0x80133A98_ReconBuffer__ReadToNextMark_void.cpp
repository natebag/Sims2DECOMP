// 0x80133A98 ReconBuffer::ReadToNextMark(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x18(31); cmpwi 0,0; beq 0f; bl _s80133A98_0; 0:; lwz 0,0xc(31); cmpwi 0,0; bne 1f; lwz 0,0x2c(31); stw 0,0x8(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80133A98_0();
extern "C" void f_80133A98() {}
