// 0x80304DF4 EController::IsStickFiltered(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; mr 4,6; bl _s80304DF4_0; mr 0,3; cmpwi 31,0; bne 0f; andis. 9,0,15; beq 1f; li 3,1; b 2f; 0:; cmpwi 31,1; bne 1f; li 3,1; andis. 9,0,240; bne 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80304DF4_0();
extern "C" void f_80304DF4() {}
