// 0x802E1804 __static_initialization_and_destruction_0 (44B)
// zeros 2 ints at SDA offset -0x58EC

extern int g_sda_ints_802E1804[2];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    volatile int* p = g_sda_ints_802E1804;
    p[0] = 0;
    p[1] = 0;
}
