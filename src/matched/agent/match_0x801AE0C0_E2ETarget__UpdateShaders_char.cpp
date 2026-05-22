// 0x801AE0C0 E2ETarget::UpdateShaders(char (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; mr 3,4; lwz 4,-30548(13); bl _s801AE0C0_0; cmpwi 3,0; bne 3f; mr 3,30; bl _s801AE0C0_1; cmpwi 3,0; bne 1f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-1412; cmpwi 0,0; beq 0f; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; lis 5,15533; lwz 6,0x7c(31); ori 5,5,28059; li 7,0; bl _s801AE0C0_2; 0:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-1396; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lis 5,6869; lwz 6,0x7c(31); ori 5,5,36475; li 7,0; bl _s801AE0C0_3; b 3f; 1:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-1412; cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lis 5,5306; lwz 6,0x7c(31); ori 5,5,26652; li 7,0; bl _s801AE0C0_4; 2:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-1396; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lis 5,-23524; lwz 6,0x7c(31); ori 5,5,39059; li 7,0; bl _s801AE0C0_5; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801AE0C0_0();
extern "C" void _s801AE0C0_1();
extern "C" void _s801AE0C0_2();
extern "C" void _s801AE0C0_3();
extern "C" void _s801AE0C0_4();
extern "C" void _s801AE0C0_5();
extern "C" void f_801AE0C0() {}
