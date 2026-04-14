// 0x8002E8A4 ERoom::SetWallState(EWallUpDownStateType) (148B)

struct ERoom {
    void SetWallState(int state);
};

extern "C" void ERoom_ApplyWallState(int flag, void* wall);  // 0x8002e84c

void ERoom::SetWallState(int state) {
    int flag = ((unsigned int)state <= 1) ? 1 : 0;
    ERoom_ApplyWallState(flag, (char*)this + 4);
    ERoom_ApplyWallState(flag, (char*)this + 16);
    ERoom_ApplyWallState(flag, (char*)this + 28);
    ERoom_ApplyWallState(flag, (char*)this + 40);
    ERoom_ApplyWallState(flag, (char*)this + 52);
    ERoom_ApplyWallState(flag, (char*)this + 64);
    ERoom_ApplyWallState(flag, (char*)this + 76);
    ERoom_ApplyWallState(flag, (char*)this + 88);
}
