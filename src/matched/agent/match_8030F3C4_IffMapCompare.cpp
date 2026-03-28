int IffMapCompare(void *a, void *b) {
    int va = *(int *)a;
    int vb = *(int *)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}
