// 0x8015EAB8 CasClothingUnlocks::~CasClothingUnlocks(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addic. 9,3,2560; beq 1f; addi 0,3,3040; cmpw 9,0; beq 1f; li 0,480; mtspr 9,0; 0:; bdnz 0b; 1:; cmpwi 3,0; beq 3f; addi 0,3,2560; cmpw 3,0; beq 3f; li 0,2560; mtspr 9,0; 2:; bdnz 2b; 3:; andi. 0,4,1; beq 4f; bl _s8015EAB8_0; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8015EAB8_0();
extern "C" void f_8015EAB8() {}
