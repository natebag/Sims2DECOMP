// 0x8039A490 THPInit (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32688; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); addi 31,4,-20320; lwz 3,-25208(13); bl _s8039A490_0; lis 4,-8192; stw 4,0x100(31); addi 4,4,8192; stw 4,0x104(31); addi 4,4,2048; stw 4,0x108(31); lis 4,-8192; stw 4,0x10c(31); addi 4,4,10240; stw 4,0x110(31); addi 4,4,2560; stw 4,0x114(31); li 3,4; oris 3,3,4; mtspr 914,3; li 3,5; oris 3,3,5; mtspr 915,3; li 3,6; oris 3,3,6; mtspr 916,3; li 3,7; oris 3,3,7; mtspr 917,3; li 0,1; stw 0,-21548(13); li 3,1; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8039A490_0();
extern "C" void f_8039A490() {}
