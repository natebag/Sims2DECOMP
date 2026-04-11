// 0x8004841C (12 bytes)
class EIFloor {
public:
    short GetTypeVersion() const;
};

extern char gEIFloorData[];

short EIFloor::GetTypeVersion() const {
    return *(short*)(gEIFloorData + 0);
}
