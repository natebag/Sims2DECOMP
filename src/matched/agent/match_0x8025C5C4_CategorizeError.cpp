// 0x8025C5C4 CategorizeError (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 0,3,-2; cmplwi 0,1024; bne 0f; stw 3,-23432(13); li 3,1; blr; 0:; rlwinm 4,3,0,8,31; addis 0,4,-6; cmplwi 0,10240; beq 1f; addis 0,4,-2; cmplwi 0,14848; beq 1f; addis 0,4,-11; cmplwi 0,23041; bne 2f; 1:; li 3,0; blr; 2:; lwz 3,-23428(13); addi 0,3,1; stw 0,-23428(13); lwz 0,-23428(13); cmpwi 0,2; bne 4f; lwz 0,-23432(13); cmplw 4,0; bne 3f; stw 4,-23432(13); li 3,1; blr; 3:; stw 4,-23432(13); li 3,2; blr; 4:; addis 0,4,-3; stw 4,-23432(13); cmplwi 0,4352; beq 5f; lwz 3,-23480(13); lwz 0,0x8(3); cmplwi 0,5; bne 6f; 5:; li 3,2; blr; 6:; li 3,3"
extern "C" void f_8025C5C4() {}
