// 0x802520A0 LockSram (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,-24704; stw 30,0x10(1); addi 30,3,0; bl _s802520A0_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s802520A0_1; li 3,0; b 1f; 0:; stw 3,0x44(31); li 0,1; add 3,31,30; stw 0,0x0(4); 1:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802520A0_0();
extern "C" void _s802520A0_1();
extern "C" void f_802520A0() {}
