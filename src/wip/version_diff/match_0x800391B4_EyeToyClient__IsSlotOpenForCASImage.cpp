/* EyeToyClient::IsSlotOpenForCASImage(int, int) at 0x800391B4 (40B) */

struct EyeToySlotEntry_ISSI { int f0, f4, open; };
extern EyeToySlotEntry_ISSI g_eyeToySlots_ISSI[8];

struct EyeToyClient_ISSI {
    static int IsSlotOpenForCASImage(int slot, int);
};

int EyeToyClient_ISSI::IsSlotOpenForCASImage(int slot, int) {
    int temp = g_eyeToySlots_ISSI[slot].open ^ 1;
    return !temp ^ 1;
}
