// 0x80136FB4 RoomManager::GetOutsideAmbientLevel(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; beq 2f; ble 1f; cmpwi 3,2; bne 0f; lis 9,-32706; lfs f0,-11436(9); b 3f; 0:; cmpwi 3,3; beq 2f; 1:; lis 9,-32706; lfs f0,-11432(9); b 3f; 2:; lis 9,-32706; lfs f0,-11428(9); 3:; lwz 9,-21356(13); lfs f1,0xc(9); fmuls f1,f1,f0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80136FB4() {}
