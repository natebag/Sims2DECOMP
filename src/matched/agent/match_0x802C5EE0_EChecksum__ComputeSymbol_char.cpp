// 0x802C5EE0 EChecksum::ComputeSymbol(char (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 8,3; mr. 4,4; li 3,-1; beq 0f; not 3,4; lbz 10,0x0(8); b 1f; 0:; lbz 9,0x0(8); addi 0,9,-48; mr 10,9; cmplwi 0,9; bgt 1f; lis 9,-32700; lis 0,255; lwz 11,-5208(9); ori 0,0,65535; xor 3,11,0; 1:; cmpwi 10,0; beq 5f; lis 9,-32700; addi 7,9,-5848; 2:; extsb 9,10; addi 0,9,-97; cmplwi 0,25; bgt 3f; addi 0,9,-32; extsb 9,0; b 4f; 3:; addi 0,9,-65; cmplwi 0,25; ble 4f; addi 0,9,-48; cmplwi 0,9; ble 4f; li 9,95; 4:; rlwinm 0,3,0,24,31; lbzu 10,0x1(8); xor 0,0,9; rlwinm 11,3,24,8,31; rlwinm 0,0,2,0,29; cmpwi 10,0; lwzx 9,7,0; xor 3,11,9; bne 2b; 5:; not 3,3"
extern "C" int f_802C5EE0() {}
