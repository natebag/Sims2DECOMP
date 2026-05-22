// 0x80196420 CASTarget::ResetSimRotations(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,4; lis 9,-32705; mtspr 9,0; lfs f0,-15264(9); li 11,0; addi 10,3,2632; 0:; mr 0,11; cmpwi 11,0; bge 1f; addi 0,11,3; 1:; rlwinm 0,0,0,0,29; lwz 9,0x1348(3); subf 0,0,11; srw 9,9,0; andi. 0,9,1; beq 2f; stfs f0,0x20c(10); 2:; addi 10,10,576; addi 11,11,1; bdnz 0b"
extern "C" void f_80196420() {}
