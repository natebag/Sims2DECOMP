/* 32-byte passthrough at 0x8009F390 */

extern void target_8009F390(void);

void sub_8009F390(void) {
    target_8009F390();
}
