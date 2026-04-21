// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: Bytes MATCH at 88B but uses placeholder externs (SomeFunc1/SomeFunc2) instead of real symbol names. Needs bl-target resolution from DOL to promote.
// Original path: src/matched/agent/match_0x8021BE8C_PlacementObject__IsLegalToPlaceAtLocation.cpp
//
struct FTilePt;
struct PlacementData;

struct PlacementObject {
    void* m_innerPtr;
    
    bool IsLegalToPlaceAtLocation(FTilePt& pt, PlacementData& data);
};

extern "C" void SomeFunc1(PlacementObject*);
extern "C" bool SomeFunc2(void*, FTilePt&, PlacementData&);

bool PlacementObject::IsLegalToPlaceAtLocation(FTilePt& pt, PlacementData& data) {
    if (!m_innerPtr) return false;
    SomeFunc1(this);
    return SomeFunc2(m_innerPtr, pt, data);
}
