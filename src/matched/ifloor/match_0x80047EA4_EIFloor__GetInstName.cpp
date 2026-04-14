/* EIFloor::GetInstName(EInstance::InstType &) at 0x80047EA4 (20B) */

extern const char g_floorInstName[];

struct EIFloor {
    const char* GetInstName(int& type);
};

const char* EIFloor::GetInstName(int& type) {
    type = 2;
    return g_floorInstName;
}
