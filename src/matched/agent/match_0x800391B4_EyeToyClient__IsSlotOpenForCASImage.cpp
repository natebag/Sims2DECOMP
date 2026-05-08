/* EyeToyClient::IsSlotOpenForCASImage(int, int) at 0x800391B4 (40B) */
//
// DOL emits the !x idiom (subfic+adde) sandwiched between two `xori r3,r3,1`,
// computing `!(open^1) ^ 1` literally. Source must keep the intermediates
// alive so GCC 2.95 can't fold them into `open != 1`.

struct EyeToySlotEntry_ISSI { int f0, f4, open; };
extern EyeToySlotEntry_ISSI g_eyeToySlots_ISSI[8];

struct EyeToyClient_ISSI {
    static int IsSlotOpenForCASImage(int slot, int);
};

int EyeToyClient_ISSI::IsSlotOpenForCASImage(int slot, int) {
    int x = g_eyeToySlots_ISSI[slot].open ^ 1;
    int y = !x;
    return y ^ 1;
}
