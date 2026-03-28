/* WorldMap getter at offset 0x74 - 0x80117EAC - 8 bytes */
/* lwz r3, 0x74(r3); blr */

class WorldMap_74 {
public:
    char _pad[0x74];
    int m_field74;

    int GetField74(void);
};

int WorldMap_74::GetField74(void) {
    return m_field74;
}
