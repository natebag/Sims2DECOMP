/* CasSimPartsS2C::OuterLayerTorsoRequiresFullTorsoMeshInMidLayer(unsigned int) const at 0x8016CD30 (40B) */

struct OLTLayerEntry {
    char data[100];
};

struct OLTLayerArray {
    char _pad[16];
    OLTLayerEntry* entries;
};

struct CasSimPartsS2C_RFMML {
    int _pad0;
    OLTLayerArray* m_arr;
    bool OuterLayerTorsoRequiresFullTorsoMeshInMidLayer(unsigned int layer) const;
};

bool CasSimPartsS2C_RFMML::OuterLayerTorsoRequiresFullTorsoMeshInMidLayer(unsigned int layer) const {
    register OLTLayerArray* p asm("r11") = m_arr;
    register OLTLayerEntry* e asm("r9") = p->entries;
    e += layer;
    return e->data[28] != 0;
}
