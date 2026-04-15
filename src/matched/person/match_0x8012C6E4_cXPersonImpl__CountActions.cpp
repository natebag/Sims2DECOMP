/* cXPersonImpl::CountActions(bool) - 0x8012C6E4 (48B) */

class cXPersonImpl {
public:
    char pad[1336];

    int CountActions(int includeCurrent);
};

int cXPersonImpl::CountActions(int includeCurrent) {
    char* base = (char*)this + 304;
    char* end = *(char**)(base + 684);
    char* begin = *(char**)(base + 680);
    int count = (int)(end - begin);
    if (includeCurrent != 0) return count;
    int flag = *(int*)((char*)this + 1332);
    if (flag == 0) return count;
    return count - 1;
}
