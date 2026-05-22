// 0x80294178 AptDate::dateIsYearLeap(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; andi. 0,4,3; bnelr; lis 9,20971; srawi 11,4,31; ori 9,9,34079; mulhw 9,4,9; srawi 0,9,5; subf 0,11,0; mulli 0,0,100; cmpw 4,0; beq 0f; li 3,1; blr; 0:; srawi 0,9,7; subf 0,11,0; mulli 0,0,400; xor 3,4,0; subfic 9,3,0; adde 3,9,3"
extern "C" int f_80294178() {}
