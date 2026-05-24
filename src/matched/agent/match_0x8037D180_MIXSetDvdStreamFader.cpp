// FLAGS: -fno-schedule-insns
// 0x8037D180 MIXSetDvdStreamFader (32 B)
// cmpwi 3,-49; bge 0f; li 3,-49; 0:; cmpwi 3,0; ble 1f; li 3,0; 1:; stw 3,-22068(13)
// Clamp fader to [-49,0] then store to SDA global.
extern int __MIXDvdStreamFader;
extern "C" void MIXSetDvdStreamFader(int value) {
    if (value < -49) value = -49;
    if (value > 0) value = 0;
    __MIXDvdStreamFader = value;
}
