// 0x8005675C __static_initialization_and_destruction_0 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 2f; cmpwi 3,0; beq 2f; li 0,4; mtspr 9,0; 0:; bdnz 0b; li 0,4; mtspr 9,0; 1:; bdnz 1b; lis 3,-32688; lis 4,-32763; lis 5,-32763; lis 6,-32763; lis 8,-32707; lis 9,-32688; addi 3,3,-19376; addi 4,4,26624; addi 5,5,26664; addi 6,6,26696; addi 8,8,14088; addi 9,9,-19456; li 7,0; bl _s8005675C_0; stw 3,-24948(13); 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8005675C_0();
extern "C" void f_8005675C() {}
