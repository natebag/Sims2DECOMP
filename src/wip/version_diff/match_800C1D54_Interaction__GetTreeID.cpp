/* Interaction::GetTreeID(void) const - 0x800C1D54 (8 bytes) */

struct Interaction {
    char m_pad[0x2C];
    short m_treeID;

    short GetTreeID(void) const;
};

short Interaction::GetTreeID(void) const {
    return m_treeID;
}
