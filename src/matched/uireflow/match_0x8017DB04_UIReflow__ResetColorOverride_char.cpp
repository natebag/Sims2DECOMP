// 0x8017DB04 UIReflow::ResetColorOverride(char (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-664(1); mfspr 0,8; stmw 28,0x288(1); stw 0,0x29c(1); lwz 0,0x4(3); mr 31,4; mr 30,5; mr 28,6; cmpwi 0,0; bne 2f; lis 9,-32706; addi 29,1,8; lwz 11,0x375c(9); lis 4,-32706; addi 9,9,14172; addi 4,4,14184; lbz 10,0x8(9); mr 3,29; lwz 0,0x4(9); stw 11,0x8(1); stw 0,0x4(29); stb 10,0x8(29); bl _s8017DB04_0; cmpwi 28,0; beq 0f; lis 4,-32706; mr 3,29; addi 4,4,14192; bl _s8017DB04_1; b 1f; 0:; lis 4,-32706; mr 3,29; addi 4,4,14196; bl _s8017DB04_2; 1:; addi 3,1,8; mr 4,31; bl _s8017DB04_3; rlwinm 28,30,24,8,31; lis 4,-32706; addi 29,1,520; addi 3,1,8; addi 4,4,14200; bl _s8017DB04_4; rlwinm 30,30,0,24,31; lis 4,-32706; addi 3,1,8; addi 4,4,14352; bl _s8017DB04_5; lis 4,-32706; addi 3,1,8; addi 4,4,14360; bl _s8017DB04_6; lis 4,-32706; mr 5,28; addi 4,4,14364; mr 3,29; crxor 6,6,6; bl _s8017DB04_7; addi 3,1,8; mr 4,29; bl _s8017DB04_8; lis 4,-32706; addi 3,1,8; addi 4,4,14372; bl _s8017DB04_9; lis 4,-32706; addi 3,1,8; addi 4,4,14308; bl _s8017DB04_10; mulli 30,30,100; lis 0,-32640; ori 0,0,32897; lis 4,-32706; mr 3,29; addi 4,4,14212; mulhwu 30,30,0; rlwinm 5,30,25,7,31; crxor 6,6,6; bl _s8017DB04_11; mr 4,29; addi 3,1,8; bl _s8017DB04_12; lis 4,-32706; addi 3,1,8; addi 4,4,14316; bl _s8017DB04_13; lis 4,-32706; addi 3,1,8; addi 4,4,14236; bl _s8017DB04_14; lis 4,-32706; lis 8,-32706; lwz 3,-25136(13); addi 4,4,14152; addi 8,8,14248; li 5,0; li 6,0; li 7,2; addi 9,1,8; crxor 6,6,6; bl _s8017DB04_15; 2:; lwz 0,0x29c(1); mtspr 8,0; lmw 28,0x288(1); addi 1,1,664"

extern "C" void _s8017DB04_0();
extern "C" void _s8017DB04_1();
extern "C" void _s8017DB04_2();
extern "C" void _s8017DB04_3();
extern "C" void _s8017DB04_4();
extern "C" void _s8017DB04_5();
extern "C" void _s8017DB04_6();
extern "C" void _s8017DB04_7();
extern "C" void _s8017DB04_8();
extern "C" void _s8017DB04_9();
extern "C" void _s8017DB04_10();
extern "C" void _s8017DB04_11();
extern "C" void _s8017DB04_12();
extern "C" void _s8017DB04_13();
extern "C" void _s8017DB04_14();
extern "C" void _s8017DB04_15();

struct UIReflow {
    void ResetColorOverride();
};

void UIReflow::ResetColorOverride() {
}
