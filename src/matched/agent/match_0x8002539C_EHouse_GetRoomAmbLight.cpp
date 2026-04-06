// MATCH: 0x8002539C EHouse::GetRoomAmbLight (16 bytes)
// Raw: 81 23 00 28 54 84 10 3A 7C 64 48 2E 4E 80 00 20

struct EHouse {
    char pad[0x28];      // 40 bytes padding
    int* roomAmbLights;  // offset 0x28 = 40
};

extern "C" int EHouse_GetRoomAmbLight(EHouse* this_, int roomIndex) {
    return this_->roomAmbLights[roomIndex];
}
