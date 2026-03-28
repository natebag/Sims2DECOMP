/* EyeToyManager::GetDimensions at 0x80328EA0 (68 bytes) */

void GetDimensionsImpl(int index, int* w, int* h);

void EyeToyManager_GetDimensions(int index, int* w, int* h)
{
    if (index != -1) {
        GetDimensionsImpl(index, w, h);
    }
    *w = 0;
    *h = 0;
}
