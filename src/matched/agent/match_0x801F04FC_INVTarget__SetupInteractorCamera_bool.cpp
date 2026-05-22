// 0x801F04FC INVTarget::SetupInteractorCamera(bool) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; cmpwi 4,0; bne 2f; lwz 3,0x84(31); lis 11,-32697; addi 11,11,23428; lis 29,-32697; rlwinm 9,3,4,0,27; add 9,9,11; lwz 30,0x100(9); cmpwi 30,0; beq 1f; bl _s801F04FC_0; cmpwi 3,0; beq 0f; lwz 0,0x84(31); addi 9,29,24012; addi 9,9,280; rlwinm 0,0,2,0,29; lwzx 3,9,0; cmpwi 3,0; beq 0f; bl _s801F04FC_1; 0:; mr 3,30; li 4,0; bl _s801F04FC_2; 1:; lis 9,-32697; li 0,8; b 4f; 2:; lwz 11,0x84(31); lis 9,-32697; addi 9,9,23428; rlwinm 11,11,4,0,27; add 11,11,9; lwz 3,0x100(11); cmpwi 3,0; beq 3f; li 4,2; bl _s801F04FC_3; 3:; lis 9,-32697; li 0,9; 4:; stw 0,0x6254(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801F04FC_0();
extern "C" void _s801F04FC_1();
extern "C" void _s801F04FC_2();
extern "C" void _s801F04FC_3();
extern "C" void f_801F04FC() {}
