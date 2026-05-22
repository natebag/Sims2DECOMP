// 0x80259C6C AlarmHandler (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); addi 0,4,-21744; lis 4,26214; subf 0,0,3; stwu 1,-32(1); addi 3,4,26215; mulhw 0,3,0; stw 31,0x1c(1); srawi 0,0,4; rlwinm 3,0,1,31,31; add 0,0,3; lis 3,-32694; rlwinm 4,0,5,0,26; addi 0,3,-21872; add 31,0,4; lwz 3,0x0(31); cmpwi 3,-1; beq 0f; lwz 4,0x4(31); lwz 5,0x8(31); lwz 6,0xc(31); lwz 7,0x10(31); lwz 8,0x14(31); bl _s80259C6C_0; cmpwi 3,0; beq 0f; li 0,-1; stw 0,0x0(31); 0:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80259C6C_0();
extern "C" void f_80259C6C() {}
