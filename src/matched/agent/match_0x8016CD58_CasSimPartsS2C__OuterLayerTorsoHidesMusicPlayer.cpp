/* CasSimPartsS2C::OuterLayerTorsoHidesMusicPlayer(unsigned int) const at 0x8016CD58 (40B) */

struct OLTLayerEntry2 {
    char data[100];
};

struct OLTLayerArray2 {
    char _pad[16];
    OLTLayerEntry2* entries;
};

struct CasSimPartsS2C_HMP {
    int _pad0;
    OLTLayerArray2* m_arr;
    bool OuterLayerTorsoHidesMusicPlayer(unsigned int layer) const;
};

bool CasSimPartsS2C_HMP::OuterLayerTorsoHidesMusicPlayer(unsigned int layer) const {
    register OLTLayerArray2* p asm("r11") = m_arr;
    register OLTLayerEntry2* e asm("r9") = p->entries;
    e += layer;
    return e->data[29] != 0;
}
