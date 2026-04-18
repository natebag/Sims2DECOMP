/* ERModel::CalcOrientedBoundBox(EMat4 &, EBound3 &) at 0x8031B3C4 (52B) */

struct EMat4_stub {};
struct EBound3_stub {
    void Compute(EBound3_stub& src, EMat4_stub& mat);
};

struct ERModel_COBB {
    char pad[88];
    EBound3_stub m_bound;
    void CalcOrientedBoundBox(EMat4_stub& mat, EBound3_stub& result);
};

void ERModel_COBB::CalcOrientedBoundBox(EMat4_stub& mat, EBound3_stub& result) {
    result.Compute(m_bound, mat);
}
