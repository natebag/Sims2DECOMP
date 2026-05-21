// 0x800D399C calculateDataSizeForList(NghResFileWriteInfo *, int &) (72B)
// ASMPROC_replace_insn: match="rlwinm 0,0,0,0,29" replacement="rlwinm 11,0,0,0,29"
// ASMPROC_replace_insn: match="add 11,0,9" replacement="add 11,11,9"

class NghResFileWriteInfo;

extern "C" int calculateDataSizeForList(NghResFileWriteInfo* p, int& outCount);

int calculateDataSizeForList(NghResFileWriteInfo* p, int& outCount) {
    int total = 0;
    int count = 0;
    if (p == 0) goto end;
    do {
        int* data = *(int**)((char*)p + 4);
        if (data) {
            total = ((total + 3) & ~3) + data[0];
            count++;
        }
        p = *(NghResFileWriteInfo**)((char*)p + 0);
    } while (p != 0);
end:
    outCount = count;
    return total;
}
