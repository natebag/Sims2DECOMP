// 0x80303620 PEmitterUnReg (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 9,0x8c(31); cmpwi 9,0; beq 0f; lwz 0,0xc(9); oris 0,0,16384; stw 0,0xc(9); lwz 9,0xb8(31); lwz 4,0x8c(31); lwz 3,0x0(9); bl _s80303620_0; li 0,0; stw 0,0xb8(31); stw 0,0x8c(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80303620_0();
extern "C" void f_80303620() {}
