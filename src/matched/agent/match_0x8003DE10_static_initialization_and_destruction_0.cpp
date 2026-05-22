// 0x8003DE10 __static_initialization_and_destruction_0 (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32697; addi 3,3,23428; bl _s8003DE10_0; lis 9,-32707; lfs f0,0x1f00(9); stfs f0,-25008(13); stfs f0,-25020(13); stfs f0,-25016(13); stfs f0,-25012(13); b 1f; 0:; lis 3,-32697; li 4,2; addi 3,3,23428; bl _s8003DE10_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8003DE10_0();
extern "C" void _s8003DE10_1();
extern "C" void f_8003DE10() {}
