// 0x80048410 (12 bytes)
class EIFloor {
public:
    const char* GetTypeKey() const;
};

extern char gEIFloorData[];

const char* EIFloor::GetTypeKey() const {
    return *(const char**)(gEIFloorData + 0);
}
