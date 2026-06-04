// 0x802DA8E4 EA::Allocator::GeneralAllocator::ReportBegin(GeneralAllocator::Snapshot*, int, int, int, int) (108 B)
// Begin a heap report. If the caller passed an existing snapshot, accept it only
// if it carries the 'SNAP' magic (else return null). If no snapshot was passed,
// take a fresh one via TakeSnapshot, mark it active (field @ +0x10 = 1), and
// return it.
namespace EA { namespace Allocator {

struct Snapshot {
    unsigned int magic;       // 0x00  'SNAP' = 0x534E4150
    char         pad4[0x0C];
    unsigned int field_10;    // 0x10
};

struct GeneralAllocator {
    Snapshot* ReportBegin(Snapshot* pSnapshot, int a2, int a3, int a4, int a5);
    Snapshot* TakeSnapshot(int a2, int a3, int a4, int a5);
};

Snapshot* GeneralAllocator::ReportBegin(Snapshot* pSnapshot, int a2, int a3, int a4, int a5)
{
    if (pSnapshot != 0) {
        unsigned int expected = 0x534E4150;
        if (pSnapshot->magic == expected)
            return pSnapshot;
        return 0;
    }

    Snapshot* snap = TakeSnapshot(a2, a3, a4, a5);
    if (snap != 0)
        snap->field_10 = 1;
    return snap;
}

}}
