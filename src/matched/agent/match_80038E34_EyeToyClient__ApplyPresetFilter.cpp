// FLAGS: -fno-elide-constructors
extern int g_eyetoyFilter;
extern int g_eyetoyFilterDirty;
void EyeToyClient_ApplyPresetFilter(int filter) {
    if (filter == g_eyetoyFilter) return;
    g_eyetoyFilter = filter;
    g_eyetoyFilterDirty = 1;
}
