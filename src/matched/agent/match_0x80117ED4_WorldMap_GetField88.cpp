/* WorldMap getter at offset 0x88 - 0x80117ED4 - 8 bytes */

class WorldMap_88 {
public:
    char _pad[0x88];
    int m_field88;

    int GetField88(void);
};

int WorldMap_88::GetField88(void) {
    return m_field88;
}
