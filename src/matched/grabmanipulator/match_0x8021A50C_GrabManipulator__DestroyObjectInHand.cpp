void GM_DestroyPlacement(void *);
void GM_SetState(void *, int);
void GM_ClearState(void *, int);

extern int gGM_ActivePlayer[];

struct GM_DestroyS {
    char _pad[0x64];
    int m_placement;

    void DestroyObjectInHand(void);
};

void GM_DestroyS::DestroyObjectInHand(void) {
    GM_DestroyPlacement(&m_placement);
    GM_SetState(this, 1);
    if (gGM_ActivePlayer[0] != 0) {
        GM_ClearState(this, 0);
    }
}
