/* FLAGS: -fno-schedule-insns */
/* 0x802DE9E8 IsSpace(char) (56 B) */
/* cmpwi 3,32; beq 0f; cmpwi 3,9; beq 0f; cmpwi 3,10; beq 0f; cmpwi 3,13; beq 0f; cmpwi 3,12; bne 1f; 0:; li 3,1; blr; 1:; li 3,0 */
/* Last check uses bne (fall-through = true case) vs previous 4 checks using beq */
extern "C" int IsSpace(char c) {
    if (c == 32 || c == 9 || c == 10 || c == 13 || c == 12) return 1;
    return 0;
}
