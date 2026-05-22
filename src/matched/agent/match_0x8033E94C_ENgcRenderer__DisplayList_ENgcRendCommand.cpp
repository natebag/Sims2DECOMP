// 0x8033E94C ENgcRenderer::DisplayList(ENgcRendCommand (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; li 30,1; lwz 0,0x8(31); cmpwi 0,0; bne 0f; li 30,0; 0:; lwz 9,0x4(31); lwz 4,0x48(9); bl _s8033E94C_0; cmpwi 30,0; beq 1f; lwz 4,0x4(31); li 5,0; lwz 3,-26392(13); bl _s8033E94C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8033E94C_0();
extern "C" void _s8033E94C_1();
extern "C" void f_8033E94C() {}
