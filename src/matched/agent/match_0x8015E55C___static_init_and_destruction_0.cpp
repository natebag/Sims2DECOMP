// 0x8015E55C __static_initialization_and_destruction_0 (52B)
// init-only static init: zeros 4 shorts at SDA offset -0x5D48

extern short g_sda_init_8015E55C[4];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    volatile short* s = g_sda_init_8015E55C;
    s[3] = 0;
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
}
