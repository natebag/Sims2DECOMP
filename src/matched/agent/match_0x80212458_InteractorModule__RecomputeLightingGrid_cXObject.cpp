// 0x80212458 InteractorModule::RecomputeLightingGrid(cXObject (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr. 11,3; lwz 31,0x5e94(9); beq 0f; lwz 9,0x4(11); lha 3,0x420(9); lwz 0,0x424(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,1; bne 1f; 0:; mr 3,31; bl _s80212458_0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80212458_0();
extern "C" void f_80212458() {}
