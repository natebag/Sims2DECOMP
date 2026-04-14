// 0x8002B99C (8 bytes) — lha r3, 0x35A(r3); blr
// Loads signed halfword from offset 0x35A

class EIWallPart {
public:
    char _pad[0x35A];
    short m_adjacentRoom;

    short GetAdjacentRoom();
};

short EIWallPart::GetAdjacentRoom() {
    return m_adjacentRoom;
}
