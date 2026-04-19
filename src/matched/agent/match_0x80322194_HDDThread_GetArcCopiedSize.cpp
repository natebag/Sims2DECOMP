// 0x80322194 (60B) HDDThread::GetArcCopiedSize(int)
// Same pattern as ArcIsCurrent: pre-seed r3=0, bgt to shared epilogue.

extern int InnerGetArcCopiedSize(void*);

class HDDThreadCS {
public:
    int GetArcCopiedSize(int);
};

int HDDThreadCS::GetArcCopiedSize(int idx) {
    int result = 0;
    if ((unsigned int)idx <= 31) {
        result = InnerGetArcCopiedSize((char*)this + (idx * 20 + 0x340));
    }
    return result;
}
