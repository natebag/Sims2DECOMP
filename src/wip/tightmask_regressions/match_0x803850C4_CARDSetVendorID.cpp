// FLAGS: -fno-schedule-insns
// 0x803850C4 CARDSetVendorID (16B)
// lhz r0,-25336(r13); sth r3,-25336(r13); mr r3,r0; blr — SDA short exchange
extern short gCARDVendorID;
short CARDSetVendorID(short newId) {
    short old = gCARDVendorID;
    gCARDVendorID = newId;
    return old;
}
