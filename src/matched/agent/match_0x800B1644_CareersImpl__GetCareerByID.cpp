// FLAGS: -msdata=eabi -G 8
// ASMPROC_region_gpr_relabel: start_anchor="lwz 9,8(3)" start_mode=after end_anchor="cmplw 0,11,10" rename="10:11,11:10"
// CareersImpl::GetCareerByID(int) at 0x800B1644 (84B)
//
// Linear search by id over m_container->careers[count]. DOL emits a
// 1.5x-unrolled loop (initial bound check + first body inline, then a
// post-increment loop with bound check + duplicate body). The early-return
// uses r3 (already 0 from the hoisted return-zero init) instead of a fresh
// counter — a coloring shortcut where the compiler observed that i and
// result both equal 0 at function entry.
//
// Source coax (goto-form `done:` epilogue separating found-paths from
// return-zero) reproduces opcode profile and branch shape natively. The
// residual diff is a clean r10/r11 swap: cc1plus picks r11 for the counter
// and r10 for count; DOL picks r10 for counter and r11 for count.
// region_gpr_relabel applies the swap across the whole function body.

struct Career { char data[20]; };

struct Container {
    int pad0;
    Career *careers;
    int pad8;
    unsigned int count;
};

class CareersImpl {
    int m_vt;
    int m_pad;
    Container *m_container;
public:
    Career *GetCareerByID(int id);
};

Career *CareersImpl::GetCareerByID(int id) {
    Container *c = m_container;
    unsigned int i = 0;
    Career *result = 0;
    unsigned int count = c->count;
    Career *arr = c->careers;

    if (i >= count) goto done;
    if (*(int *)arr == id) { result = arr; goto done; }

loop:
    i++;
    arr = (Career *)((char *)arr + 20);
    if (i >= count) goto done;
    if (*(int *)arr == id) { result = arr; goto done; }
    goto loop;

done:
    return result;
}
