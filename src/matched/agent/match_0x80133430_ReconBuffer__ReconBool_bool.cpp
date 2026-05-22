// 0x80133430 ReconBuffer::ReconBool(bool (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,4; li 5,1; lwz 0,0x0(31); addi 4,1,8; stb 0,0x8(1); bl _s80133430_0; lbz 0,0x8(1); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; stw 9,0x0(31); lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80133430_0();
extern "C" void f_80133430() {}
