/* Neighbor::GetRelations(void) const - 0x800C90B4 (8 bytes) */

struct Neighbor {
    char m_pad[0x10];
    void *m_relations;

    void *GetRelations(void) const;
};

void *Neighbor::GetRelations(void) const {
    return m_relations;
}
