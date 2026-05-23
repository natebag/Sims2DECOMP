extern "C" int getRouteState(void*);
int cXPersonImpl_IsRouting(void* self) {
    if (getRouteState(self) != 0) return 1;
    return 0;
}
