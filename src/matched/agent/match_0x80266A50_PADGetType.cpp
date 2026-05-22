// 0x80266A50 PADGetType (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s80266A50_0; stw 3,0x0(31); lis 0,-32768; srw 3,0,30; lwz 0,-23176(13); and. 0,0,3; bne 0f; lwz 0,-27652(13); cmpw 0,30; beq 0f; lwz 0,-23180(13); and. 0,0,3; bne 1f; 0:; li 3,0; b 2f; 1:; li 3,1; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80266A50_0();
extern "C" void f_80266A50() {}
