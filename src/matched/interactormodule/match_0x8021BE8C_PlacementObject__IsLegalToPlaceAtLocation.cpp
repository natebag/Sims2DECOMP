// 0x8021BE8C InteractorModule::PlacementObject::IsLegalToPlaceAtLocation(FTilePt&, PlacementData&) (88B)

struct cXObject;
struct FTilePt;

namespace InteractorModule {

struct PlacementData;

class PlacementObject {
public:
    cXObject* m_obj;  // 0x00
    void Pickup();
    int IsLegalToPlaceAtLocation(FTilePt& tile, PlacementData& data);
};

extern int IsLegalToPlaceAtLocation(cXObject* obj, FTilePt& tile, PlacementData* data);

int PlacementObject::IsLegalToPlaceAtLocation(FTilePt& tile, PlacementData& data) {
    int result = 0;
    if (m_obj != 0) {
        Pickup();
        result = InteractorModule::IsLegalToPlaceAtLocation(m_obj, tile, &data);
    }
    return result;
}

}
