// 0x80048434 (12 bytes)
class EIFloor {
public:
    short GetReadVersion() const;
};

extern char gEIFloorData[];

short EIFloor::GetReadVersion() const {
    return *(short*)(gEIFloorData + 0);
}
