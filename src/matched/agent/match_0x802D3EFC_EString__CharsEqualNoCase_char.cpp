// 0x802D3EFC EString::CharsEqualNoCase(char, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; cmpw 9,4; bne 0f; li 3,1; blr; 0:; addi 0,9,-97; cmplwi 0,25; bgt 1f; cmpwi 4,64; ble 1f; cmpwi 4,90; bgt 1f; addi 3,9,-32; xor 3,3,4; subfic 0,3,0; adde 3,0,3; blr; 1:; addi 0,4,-97; cmplwi 0,25; bgt 2f; cmpwi 9,64; ble 2f; cmpwi 9,90; bgt 2f; addi 3,4,-32; xor 3,3,9; subfic 0,3,0; adde 3,0,3; blr; 2:; li 3,0"
extern "C" int f_802D3EFC() {}
