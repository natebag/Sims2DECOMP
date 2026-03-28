/* 36-byte wrapper at 0x80246F0C: loads SDA global and calls */

extern void *g_sda_80246F0C;
extern void target_80246F0C(void*);

void sub_80246F0C(void) {
    target_80246F0C(g_sda_80246F0C);
}
