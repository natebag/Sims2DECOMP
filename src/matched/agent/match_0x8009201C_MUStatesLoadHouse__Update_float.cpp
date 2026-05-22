// 0x8009201C MUStatesLoadHouse::Update(float) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x8(31); lwz 0,0x90(3); cmpwi 0,0; bne 3f; lwz 0,0x1c(31); cmpwi 0,0; bne 0f; lis 9,-32706; li 0,8; lfs f0,-32052(9); stw 0,0x1c(31); stfs f0,0x20(31); b 6f; 0:; cmpwi 0,8; bne 1f; lfs f0,0x20(31); lis 9,-32706; lfs f13,-32048(9); fsubs f0,f0,f1; fcmpu 0,f0,f13; stfs f0,0x20(31); bgt 6f; li 0,9; stw 0,0x1c(31); b 6f; 1:; cmpwi 0,9; bne 2f; lis 9,-32697; lwz 11,0x5e94(9); lwz 3,0x54(11); bl _s8009201C_0; li 0,10; stw 0,0x1c(31); b 6f; 2:; cmpwi 0,10; bne 6f; lfs f0,0x20(31); lis 9,-32706; lfs f13,-32044(9); fsubs f0,f0,f1; fcmpu 0,f0,f13; stfs f0,0x20(31); bgt 6f; li 4,2; bl _s8009201C_1; b 6f; 3:; cmpwi 0,1; beq 6f; cmpwi 0,2; bne 6f; lwz 0,0x1c(31); cmpwi 0,1; beq 4f; cmpwi 0,11; beq 4f; cmpwi 0,2; beq 4f; cmpwi 0,3; beq 4f; cmpwi 0,4; beq 4f; cmpwi 0,5; beq 4f; cmpwi 0,6; beq 4f; cmpwi 0,13; beq 4f; cmpwi 0,7; bne 5f; 4:; lwz 3,0x8(31); li 4,1; bl _s8009201C_2; b 6f; 5:; cmpwi 0,12; bne 6f; li 0,0; stw 0,0x1c(31); stw 0,0x90(3); 6:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8009201C_0();
extern "C" void _s8009201C_1();
extern "C" void _s8009201C_2();
extern "C" void f_8009201C() {}
