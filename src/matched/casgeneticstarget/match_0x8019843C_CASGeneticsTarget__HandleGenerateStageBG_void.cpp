// 0x8019843C CASGeneticsTarget::HandleGenerateStageBG(void) (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 27,0x13c(1); stw 0,0x154(1); lis 9,-32697; lwz 4,0x5bc0(9); cmpwi 4,0; beq 6f; lwz 0,0x84(4); cmpwi 0,0; beq 6f; lwz 29,0x1370(4); cmpwi 29,0; beq 6f; lwz 0,-31440(13); cmpwi 0,1; bne 1f; lwz 3,0x2fc(29); cmpwi 3,0; beq 0f; li 4,3; bl _s8019843C_0; 0:; li 0,0; li 3,360; stw 0,0x2fc(29); bl _s8019843C_1; bl _s8019843C_2; mr 30,3; li 5,1; addi 4,29,172; bl _s8019843C_3; lwz 4,-21168(13); b 3f; 1:; cmpwi 0,2; bne 4f; lwz 3,0x2fc(29); cmpwi 3,0; beq 2f; li 4,3; bl _s8019843C_4; 2:; li 0,0; li 3,360; stw 0,0x2fc(29); bl _s8019843C_5; bl _s8019843C_6; mr 30,3; li 5,1; addi 4,29,464; bl _s8019843C_7; lwz 4,-21164(13); 3:; mr 3,30; bl _s8019843C_8; mr 3,30; bl _s8019843C_9; mr 3,30; bl _s8019843C_10; mr 3,30; bl _s8019843C_11; mr 3,30; bl _s8019843C_12; mr 3,30; bl _s8019843C_13; stw 30,0x2fc(29); b 6f; 4:; cmpwi 0,4; bne 6f; lwz 31,0x84(29); addi 30,1,8; addi 28,30,8; mr 27,30; mr 3,31; bl _s8019843C_14; lwz 0,0x2f4(29); lis 9,-32698; mr 29,3; addi 9,9,24616; xori 0,0,1; subfic 11,0,0; adde 0,11,0; mr 3,28; stw 0,0x84(29); stw 9,0x4(30); bl _s8019843C_15; li 0,0; li 9,288; stw 0,0x8(1); 5:; lwz 0,0x0(29); addic. 9,9,-24; stw 0,0x0(28); lwz 0,0x4(29); stw 0,0x4(28); lwz 0,0x8(29); stw 0,0x8(28); lwz 0,0xc(29); stw 0,0xc(28); lwz 0,0x10(29); stw 0,0x10(28); lwz 0,0x14(29); addi 29,29,24; stw 0,0x14(28); addi 28,28,24; bne 5b; lwz 0,0x0(29); mr 3,31; addi 4,1,8; stw 0,0x0(28); bl _s8019843C_16; lis 9,-32698; mr 3,27; addi 9,9,24616; li 4,2; stw 9,0x4(27); bl _s8019843C_17; 6:; lwz 0,0x154(1); mtspr 8,0; lmw 27,0x13c(1); addi 1,1,336"

extern "C" void _s8019843C_0();
extern "C" void _s8019843C_1();
extern "C" void _s8019843C_2();
extern "C" void _s8019843C_3();
extern "C" void _s8019843C_4();
extern "C" void _s8019843C_5();
extern "C" void _s8019843C_6();
extern "C" void _s8019843C_7();
extern "C" void _s8019843C_8();
extern "C" void _s8019843C_9();
extern "C" void _s8019843C_10();
extern "C" void _s8019843C_11();
extern "C" void _s8019843C_12();
extern "C" void _s8019843C_13();
extern "C" void _s8019843C_14();
extern "C" void _s8019843C_15();
extern "C" void _s8019843C_16();
extern "C" void _s8019843C_17();

struct CASGeneticsTarget {
    void HandleGenerateStageBG();
};

void CASGeneticsTarget::HandleGenerateStageBG() {
}
