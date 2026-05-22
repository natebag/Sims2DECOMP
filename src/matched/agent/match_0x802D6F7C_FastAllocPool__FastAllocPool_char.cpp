// 0x802D6F7C FastAllocPool::FastAllocPool(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; li 0,0; addi 9,9,-23848; stw 9,0x14(31); mr. 4,5; stw 0,0x10(31); stw 0,0x0(31); stw 0,0x4(31); stw 0,0x8(31); stw 0,0xc(31); beq 0f; cmpwi 6,0; beq 0f; cmpwi 7,0; beq 0f; mr 5,6; mr 6,7; bl _s802D6F7C_0; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D6F7C_0();
extern "C" void f_802D6F7C() {}
