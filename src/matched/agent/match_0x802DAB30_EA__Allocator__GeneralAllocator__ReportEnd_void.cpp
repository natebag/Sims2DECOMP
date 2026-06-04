// 0x802DAB30 EA::Allocator::GeneralAllocator::ReportEnd(GeneralAllocator::Snapshot*) (80 B)
// Close out a heap report. Ignore a null or non-'SNAP' report. If the snapshot
// still owns allocated state (field @ +0x10 non-zero) free it via FreeSnapshot;
// otherwise clear the report's trailing field (@ +0x28) to zero.
namespace EA { namespace Allocator {

struct Snapshot {
    unsigned int magic;       // 0x00  'SNAP' = 0x534E4150
    char         pad4[0x0C];
    unsigned int field_10;    // 0x10
    char         pad14[0x14];
    unsigned int field_28;    // 0x28
};

struct GeneralAllocator {
    void ReportEnd(Snapshot* report);
    void FreeSnapshot(Snapshot* snap);
};

void GeneralAllocator::ReportEnd(Snapshot* report)
{
    if (report == 0)
        return;
    if (report->magic != 0x534E4150)
        return;

    unsigned int owned = report->field_10;
    if (owned != 0)
        FreeSnapshot(report);
    else
        report->field_28 = owned;
}

}}
