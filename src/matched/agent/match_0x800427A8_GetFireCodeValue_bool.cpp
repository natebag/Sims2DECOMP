// 0x800427A8 GetFireCodeValue(bool) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 3,0; beq 0f; lis 3,-32697; addi 3,3,23428; addi 3,3,4; bl _s800427A8_0; 0:; lis 9,-32697; lis 11,-32707; lfs f13,0x5b90(9); lfs f0,0x2900(11); fcmpu 0,f13,f0; cror 3,2,1; bns 1f; lis 9,-32697; lwz 0,0x6168(9); cmpwi 0,0; beq 1f; lis 9,-32707; lfs f1,0x2904(9); b 2f; 1:; lis 9,-32697; lfs f1,0x5b90(9); 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800427A8_0();
extern "C" void f_800427A8() {}
