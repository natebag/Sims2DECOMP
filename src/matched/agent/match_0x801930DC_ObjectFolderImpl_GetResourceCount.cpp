
void* __builtin_new_fn(unsigned int);
void* ThumbnailEncode_ctor(void*);
void NeighborhoodDeleteChar(void*);

class ObjectFolderImpl {
public:
    void* GetResourceCount(int type, unsigned int, unsigned int);
};

void* ObjectFolderImpl::GetResourceCount(int type, unsigned int, unsigned int) {
    void* result;

    if (type < 0)
        goto fail;
    if (type > 3)
        goto check_high;

    result = __builtin_new_fn(2848);
    result = ThumbnailEncode_ctor(result);
    goto check_result;

check_high:
    if (type <= 5)
        return 0;

fail:
    return 0;

check_result:
    if (result != 0) {
        NeighborhoodDeleteChar(result);
    }
    return result;
}
