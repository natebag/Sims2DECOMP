// 0x8001EAC4 (8 bytes) — lhz r3, 0x544(r3); blr

class ESimsCam {
public:
    char _pad[0x544];
    unsigned short m_roomId;

    unsigned short GetRoomId();
};

unsigned short ESimsCam::GetRoomId() {
    return m_roomId;
}
