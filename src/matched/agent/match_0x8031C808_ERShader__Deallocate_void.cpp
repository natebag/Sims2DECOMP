// 0x8031C808 ERShader::Deallocate(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x0(31); lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; lwz 30,0x14(31); lis 3,-32692; cmpwi 30,0; beq 2f; lwz 4,0x6c(30); cmpwi 4,0; beq 0f; addi 3,3,-17444; bl _s8031C808_0; li 0,0; stw 0,0x6c(30); 0:; lwz 4,0x68(30); cmpwi 4,0; beq 1f; lis 3,-32692; addi 3,3,-17444; bl _s8031C808_1; li 0,0; stw 0,0x68(30); 1:; lwz 11,-26392(13); lwz 4,0x14(31); lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x14(31); 2:; lis 9,-32702; li 29,0; lfs f0,0xa28(9); lis 30,-32692; lwz 4,0x34(31); addi 3,30,-17444; stw 29,0x30(31); stfs f0,0x60(31); bl _s8031C808_2; lwz 4,0x38(31); addi 3,30,-17444; bl _s8031C808_3; lwz 4,0x68(31); addi 3,30,-17444; bl _s8031C808_4; stw 29,0x68(31); stw 29,0x34(31); stw 29,0x38(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031C808_0();
extern "C" void _s8031C808_1();
extern "C" void _s8031C808_2();
extern "C" void _s8031C808_3();
extern "C" void _s8031C808_4();
extern "C" void f_8031C808() {}
