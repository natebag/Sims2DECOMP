// 0x80248994 __smakebuf (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stw 31,0x4c(1); stw 0,0x54(1); mr 31,3; lhz 0,0xc(31); andi. 9,0,2; beq 0f; addi 9,31,74; li 0,1; stw 0,0x14(31); stw 9,0x10(31); stw 9,0x0(31); b 3f; 0:; lha 4,0xe(31); cmpwi 4,0; blt 1f; lwz 3,0x5c(31); addi 5,1,8; bl _s80248994_0; cmpwi 3,0; blt 1f; lwz 9,0xc(1); li 0,0; ori 0,0,32768; rlwinm 9,9,0,16,19; cmpw 9,0; bne 1f; lwz 0,0x28(31); lis 9,-32731; addi 9,9,-29484; cmpw 0,9; bne 1f; lhz 0,0xc(31); li 9,1024; stw 9,0x54(31); ori 0,0,1024; b 2f; 1:; lhz 0,0xc(31); ori 0,0,2048; 2:; sth 0,0xc(31); lhz 0,0xc(31); addi 11,31,74; li 9,1; stw 11,0x10(31); ori 0,0,2; stw 9,0x14(31); sth 0,0xc(31); stw 11,0x0(31); 3:; lwz 0,0x54(1); mtspr 8,0; lwz 31,0x4c(1); addi 1,1,80"
extern "C" void _s80248994_0();
extern "C" void f_80248994() {}
