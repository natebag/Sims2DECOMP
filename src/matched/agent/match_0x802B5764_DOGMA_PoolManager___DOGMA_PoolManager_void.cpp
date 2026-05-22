// 0x802B5764 DOGMA_PoolManager::~DOGMA_PoolManager(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32694; mr 31,3; addi 9,9,-16288; lwz 11,0xc(31); lwz 0,0x8(9); mr 28,4; addi 4,11,4; lwz 3,0x0(31); mtspr 8,0; mr 29,9; blrl; lwz 30,0x4(31); 0:; lwz 9,0x4(29); mr 3,30; lwz 30,0x0(30); mtspr 8,9; blrl; mr. 30,30; bne 0b; lwz 30,0x14(31); cmpwi 30,0; beq 2f; lis 9,-32694; addi 29,9,-16288; 1:; lwz 9,0x4(29); mr 3,30; lwz 30,0x0(30); mtspr 8,9; blrl; mr. 30,30; bne 1b; 2:; andi. 0,28,1; beq 3f; mr 3,31; li 4,32; bl _s802B5764_0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802B5764_0();
extern "C" void f_802B5764() {}
