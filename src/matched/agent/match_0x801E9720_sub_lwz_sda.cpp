/* 36-byte wrapper at 0x801E9720: loads SDA global and calls */

extern void *g_sda_801E9720;
extern void target_801E9720(void*);

void sub_801E9720(void) {
    target_801E9720(g_sda_801E9720);
}
