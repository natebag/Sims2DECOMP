// 0x801DE4B4 RCPTarget::Update(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x144(3); cmpwi 0,0; bne 0f; lis 9,-32705; lfs f13,0x140(3); lfs f12,0x52ac(9); fcmpu 0,f13,f12; ble 0f; lfs f0,-26800(13); fsubs f0,f13,f0; fcmpu 0,f0,f12; stfs f0,0x140(3); cror 3,2,0; bns 0f; lwz 11,0x120(3); li 0,1; stw 0,0x144(3); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801DE4B4() {}
