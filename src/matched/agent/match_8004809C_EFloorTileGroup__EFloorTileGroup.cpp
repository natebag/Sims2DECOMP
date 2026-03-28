/* EFloorTileGroup::EFloorTileGroup(ERShader *, EDL *, EFloorTileStrip *, int, EFloorTileGroup *) at 0x8004809C (72B) */

struct EResource {
    void AddRef(void);
};

struct ERShader : EResource {};
struct EDL;
struct EFloorTileStrip;

struct EFloorTileGroup {
    EFloorTileGroup *m_next;
    EDL *m_edl;
    int m_count;
    EFloorTileStrip *m_strips;
    ERShader *m_shader;

    EFloorTileGroup(ERShader *shader, EDL *edl, EFloorTileStrip *strips, int count, EFloorTileGroup *next);
};

EFloorTileGroup::EFloorTileGroup(ERShader *shader, EDL *edl, EFloorTileStrip *strips, int count, EFloorTileGroup *next) {
    m_edl = edl;
    m_strips = strips;
    m_count = count;
    m_next = next;
    m_shader = shader;
    shader->AddRef();
}
