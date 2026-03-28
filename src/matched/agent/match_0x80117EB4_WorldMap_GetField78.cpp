/* WorldMap getter at offset 0x78 - 0x80117EB4 - 8 bytes */

class WorldMap_78 {
public:
    char _pad[0x78];
    int m_field78;

    int GetField78(void);
};

int WorldMap_78::GetField78(void) {
    return m_field78;
}
