// 0x80327AE8 EResourceMap::Find(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; bl _s80327AE8_0; lwz 0,0x4(31); cmpw 3,0; bge 1f; lwz 11,0x0(31); rlwinm 9,3,3,0,28; lwzx 0,9,11; add 10,9,11; cmpw 0,30; bne 1f; cmpwi 29,0; beq 0f; lwz 0,0x4(10); stw 0,0x0(29); 0:; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80327AE8_0();
extern "C" void f_80327AE8() {}
