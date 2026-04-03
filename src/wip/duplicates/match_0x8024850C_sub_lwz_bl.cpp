/* 36-byte wrapper at 0x8024850C: loads SDA global and calls */

extern void *g_sda_8024850C;
extern void target_8024850C(void*);

void sub_8024850C(void) {
    target_8024850C(g_sda_8024850C);
}
