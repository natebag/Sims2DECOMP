// 0x8002B99C EIWallPart::GetAdjacentRoom(void) (8 B)
struct EIWallPart { char _pad[0x35a]; short m_adjacentRoom; int GetAdjacentRoom(); };
int EIWallPart::GetAdjacentRoom() { return m_adjacentRoom; }
