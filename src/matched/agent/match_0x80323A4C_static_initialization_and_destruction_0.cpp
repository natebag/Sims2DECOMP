// 0x80323A4C __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmpwi 3,0; beq 1f; li 0,4; lis 9,-32702; mtspr 9,0; lis 11,-32693; lfs f0,0xc70(9); addi 11,11,24504; 0:; stfs f0,0x0(11); stfs f0,0x4(11); addi 11,11,8; bdnz 0b; blr; 1:; lis 9,-32693; addi 9,9,24504; cmpwi 9,0; beqlr; addi 11,9,32; cmpw 11,9; beqlr; 2:; addi 11,11,-8; cmpw 11,9; bne 2b"
extern "C" void f_80323A4C() {}
