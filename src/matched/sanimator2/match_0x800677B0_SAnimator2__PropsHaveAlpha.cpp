// 0x800677B0 (108B) SAnimator2::PropsHaveAlpha(void)

class SAnimator2 {
public:
    int PropsHaveAlpha();
};

int SAnimator2::PropsHaveAlpha() {
    void** start = *(void***)((char*)this + 360);
    int i = 0;
    void** end = *(void***)((char*)this + 364);
    int count = (int)(end - start);
    int flag = 0;
    if (i >= count) goto end;

    {
        void** p = start;
        for (; i < count; i++) {
            void* obj = *p;
            p++;
            void* sub = *(void**)((char*)obj + 8);
            if (sub != 0) {
                flag = (flag != 0) | (*(int*)((char*)sub + 256) != 0);
            }
        }
    }
end:
    return flag;
}
