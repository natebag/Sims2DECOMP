// 0x8001EACC (8 bytes) — lwz r3, 0x548(r3); blr

class ESimsCam {
public:
    char _pad[0x548];
    int m_roomWallsOpaque;

    int GetRoomWallsOpaque();
};

int ESimsCam::GetRoomWallsOpaque() {
    return m_roomWallsOpaque;
}
