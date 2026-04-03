// 0x8002B99C (8 bytes)
class EIWallPart {
public:
    short GetAdjacentRoom();
};

short EIWallPart::GetAdjacentRoom() {
    return *(short*)((char*)this + 0x35A);
}
