// 0x8002539C (16 bytes)
// lwz r9, 0x28(r3); slwi r4, r4, 2; lwzx r3, r4, r9; blr

class EHouse {
public:
    void* GetRoomAmbLight(int index);
};

__attribute__((naked))
void* EHouse::GetRoomAmbLight(int index) {
    asm volatile(
        "lwz 9, 0x28(3)\n"
        "slwi 4, 4, 2\n"
        "lwzx 3, 4, 9\n"
        "blr\n"
    );
}
