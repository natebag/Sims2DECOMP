// 0x802622F4 getTiming (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,30; lis 4,-32700; addi 5,4,-12696; bgt 0f; lis 4,-32700; addi 4,4,-12196; rlwinm 0,3,2,0,29; lwzx 0,4,0; mtspr 9,0; bctr; addi 3,5,68; blr; addi 3,5,106; blr; addi 3,5,144; blr; addi 3,5,182; blr; addi 3,5,68; blr; addi 3,5,106; blr; addi 3,5,220; blr; addi 3,5,258; blr; addi 3,5,296; blr; addi 3,5,334; blr; addi 3,5,144; blr; addi 3,5,182; blr; addi 3,5,372; blr; addi 3,5,410; blr; lwz 3,-23196(13); blr; 0:; li 3,0"
extern "C" int f_802622F4() {}
