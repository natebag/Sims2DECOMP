// 0x80266AC4 PADSync (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); li 31,0; addi 3,31,0; lwz 0,-23176(13); cmplwi 0,0; bne 0f; lwz 0,-27652(13); cmpwi 0,32; bne 0f; li 3,1; 0:; cmpwi 3,0; beq 1f; bl _s80266AC4_0; cmpwi 3,0; bne 1f; li 31,1; 1:; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80266AC4_0();
extern "C" void f_80266AC4() {}
