// 0x8004841C (12 bytes)
class EIFloor {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEIFloorData[];

unsigned short EIFloor::GetTypeVersion() const {
    return gEIFloorData[0];
}
