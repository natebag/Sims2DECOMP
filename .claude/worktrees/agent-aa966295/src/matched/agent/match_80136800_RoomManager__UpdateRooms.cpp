// 0x80136800 (72 bytes)
// RoomManager::UpdateRooms(void)

class RoomManager { public: void UpdateRooms(void); };

__attribute__((naked))
void RoomManager::UpdateRooms(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030020\n.long 0x2C000000\n.long 0x41820024\n.long 0x4BFFFA5D\n.long 0x806DAC50\n.long 0x81230000\n.long 0xA8090070\n.long 0x81290074\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
