// 0x80048434 (12 bytes)
class EIFloor {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gEIFloorData[];

unsigned short EIFloor::GetReadVersion() const {
    return gEIFloorData[1];
}
