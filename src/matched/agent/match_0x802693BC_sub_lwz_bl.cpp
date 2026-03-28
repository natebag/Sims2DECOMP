/* 36-byte wrapper at 0x802693BC: loads SDA global and calls */

extern void *g_sda_802693BC;
extern void target_802693BC(void*);

void sub_802693BC(void) {
    target_802693BC(g_sda_802693BC);
}
