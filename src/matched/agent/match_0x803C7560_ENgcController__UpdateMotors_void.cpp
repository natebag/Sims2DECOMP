// 0x803C7560 ENgcController::UpdateMotors(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s803C7560_0; cmpwi 3,6; bgt 0f; cmpwi 3,4; bge 1f; cmpwi 3,0; beq 4f; cmpwi 3,2; beq 4f; b 2f; 0:; cmpwi 3,8; beq 4f; cmpwi 3,11; bne 2f; 1:; li 0,1; b 3f; 2:; li 0,0; 3:; stw 0,-26520(13); 4:; lwz 0,-26520(13); cmpwi 0,0; bne 5f; lis 9,-32702; lfs f0,0x1dc(31); lfs f13,0x15d0(9); fcmpu 0,f0,f13; ble 5f; lfs f0,0x1e0(31); fcmpu 0,f0,f13; ble 5f; lwz 3,0x20c(31); li 4,1; bl _s803C7560_1; b 6f; 5:; lwz 3,0x20c(31); li 4,0; bl _s803C7560_2; 6:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803C7560_0();
extern "C" void _s803C7560_1();
extern "C" void _s803C7560_2();
extern "C" void f_803C7560() {}
