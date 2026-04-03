// 0x8001EACC (8 bytes)
class ESimsCam {
public:
    int GetRoomWallsOpaque();
};

int ESimsCam::GetRoomWallsOpaque() {
    return *(int*)((char*)this + 0x548);
}
