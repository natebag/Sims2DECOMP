// 0x803520DC Effects::PreComputeRand32Table(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,128; lis 9,-32690; mtspr 9,0; lis 11,-32690; addi 6,9,-13312; addi 7,11,-13824; 0:; lwz 9,-22464(13); addi 0,9,2; addic. 8,9,-1; bge 1f; li 8,19; b 2f; 1:; cmpwi 0,19; ble 2f; addi 0,9,-18; 2:; rlwinm 10,8,2,0,29; rlwinm 0,0,2,0,29; lwzx 11,6,0; lwzx 9,10,6; stw 8,-22464(13); add 9,9,11; stw 9,0x0(7); stwx 9,10,6; addi 7,7,4; bdnz 0b; li 0,0; stw 0,-25888(13)"
extern "C" void f_803520DC() {}
