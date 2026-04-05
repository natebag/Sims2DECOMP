void *GetObjectNode(void);
int IsLegalToPlaceMultiTile(int, void *, void *);

struct IM_Legal {
    void *m_field00;
    int m_field04;

    int IsLegalToPlaceMultiTileAtLocation(void *obj, void *tilePt);
};

int IM_Legal::IsLegalToPlaceMultiTileAtLocation(void *obj, void *tilePt) {
    void *node = GetObjectNode();
    int val = 0;
    if (node != 0) {
        val = *(int *)((char *)node + 4);
    }
    int interactorIndex = val;
    return IsLegalToPlaceMultiTile(interactorIndex, obj, tilePt);
}
