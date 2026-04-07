// 0x801270E0 IsPermittedToRunCheckTreeForAds (52B)

int IsPermittedToRunCheckTreeForAds(int objType, int interaction) {
    if (objType == (int)0xC867A344) {
        if (interaction == 2) return 1;
        if (interaction == 10) return 1;
    }
    return 0;
}
