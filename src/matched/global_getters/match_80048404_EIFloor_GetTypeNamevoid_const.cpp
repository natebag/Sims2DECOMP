// 0x80048404 (12 bytes)
class EIFloor {
public:
    const char* GetTypeName() const;
};

extern char gEIFloorData[];

const char* EIFloor::GetTypeName() const {
    return *(const char**)(gEIFloorData + 0);
}
