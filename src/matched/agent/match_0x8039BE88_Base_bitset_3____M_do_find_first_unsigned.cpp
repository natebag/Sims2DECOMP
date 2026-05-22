// 0x8039BE88 _Base_bitset<3>::_M_do_find_first(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 7,0; lis 6,-32698; li 8,0; 0:; lwz 11,0x0(3); addi 3,3,4; cmpwi 11,0; beq 3f; li 0,4; addi 10,6,-22032; mtspr 9,0; mr 9,8; 1:; rlwinm 0,11,0,24,31; cmpwi 0,0; beq 2f; lbzx 3,10,0; add 3,9,3; blr; 2:; rlwinm 11,11,24,8,31; addi 9,9,8; bdnz 1b; 3:; addi 7,7,1; addi 8,8,32; cmplwi 7,2; ble 0b; mr 3,4"
extern "C" int f_8039BE88() {}
