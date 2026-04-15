// 0x80211C8C InteractorModule::IsLegalToPlaceMultiTileAtLocation(cXObject *, FTilePt &) (76B)

struct cXObject;
struct FTilePt;

extern cXObject* GetLeadObjectImpl(cXObject*);
extern int CoreIsLegalToPlace(cXObject*, FTilePt&, int&);

int IsLegalToPlaceMultiTileAtLocation(cXObject* obj, FTilePt& pt) {
    cXObject* lead = GetLeadObjectImpl(obj);
    cXObject* arg = 0;
    if (lead != 0) {
        arg = *(cXObject**)((char*)lead + 4);
    }
    int unused;
    return CoreIsLegalToPlace(arg, pt, unused);
}
