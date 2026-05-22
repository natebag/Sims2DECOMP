// 0x8009508C PreGameFreeplayState::Update(float) (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 9,0x8(31); lwz 30,0x90(9); cmpwi 30,0; beq 0f; li 0,0; stw 0,0x90(9); bl _s8009508C_0; lwz 3,0x1c(31); xori 4,30,1; subfic 0,4,0; adde 4,0,4; bl _s8009508C_1; 0:; lwz 3,0x8(31); bl _s8009508C_2; cmpwi 3,0; beq 8f; lwz 3,0x8(31); bl _s8009508C_3; cmpwi 3,6; beq 2f; bgt 1f; cmpwi 3,4; beq 4f; b 8f; 1:; cmpwi 3,50; beq 6f; b 8f; 2:; bl _s8009508C_4; cmpwi 3,0; bne 3f; li 3,4; bl _s8009508C_5; b 8f; 3:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 8f; lwz 3,0x8(31); lis 30,-32697; bl _s8009508C_6; li 11,0; lis 9,-32697; li 0,-1; stw 11,-28408(13); stw 0,0x6230(9); addi 3,30,23428; stw 11,-28404(13); bl _s8009508C_7; addi 3,30,23428; bl _s8009508C_8; addi 3,30,23428; bl _s8009508C_9; lis 9,-32706; mr 3,31; lfs f1,-31164(9); li 4,13; bl _s8009508C_10; b 8f; 4:; bl _s8009508C_11; cmpwi 3,0; bne 5f; li 3,3; bl _s8009508C_12; b 8f; 5:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 8f; lwz 3,0x8(31); bl _s8009508C_13; lwz 3,0x1c(31); bl _s8009508C_14; li 0,0; mr 3,31; stw 0,-28408(13); li 4,12; stw 0,-28404(13); bl _s8009508C_15; b 8f; 6:; bl _s8009508C_16; cmpwi 3,0; bne 7f; li 3,0; bl _s8009508C_17; b 8f; 7:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 8f; lis 30,-32693; lis 4,-17873; addi 30,30,31260; li 6,0; ori 4,4,14905; li 5,0; mr 3,30; bl _s8009508C_18; lis 4,-17873; mr 3,30; ori 4,4,14905; li 5,1; bl _s8009508C_19; lwz 3,0x8(31); bl _s8009508C_20; li 0,0; mr 3,31; stw 0,-28408(13); li 4,1; stw 0,-28404(13); bl _s8009508C_21; 8:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8009508C_0();
extern "C" void _s8009508C_1();
extern "C" void _s8009508C_2();
extern "C" void _s8009508C_3();
extern "C" void _s8009508C_4();
extern "C" void _s8009508C_5();
extern "C" void _s8009508C_6();
extern "C" void _s8009508C_7();
extern "C" void _s8009508C_8();
extern "C" void _s8009508C_9();
extern "C" void _s8009508C_10();
extern "C" void _s8009508C_11();
extern "C" void _s8009508C_12();
extern "C" void _s8009508C_13();
extern "C" void _s8009508C_14();
extern "C" void _s8009508C_15();
extern "C" void _s8009508C_16();
extern "C" void _s8009508C_17();
extern "C" void _s8009508C_18();
extern "C" void _s8009508C_19();
extern "C" void _s8009508C_20();
extern "C" void _s8009508C_21();
extern "C" void f_8009508C() {}
