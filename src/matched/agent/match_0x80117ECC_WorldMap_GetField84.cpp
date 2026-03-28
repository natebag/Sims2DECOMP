/* WorldMap getter at offset 0x84 - 0x80117ECC - 8 bytes */

class WorldMap_84 {
public:
    char _pad[0x84];
    int m_field84;

    int GetField84(void);
};

int WorldMap_84::GetField84(void) {
    return m_field84;
}
