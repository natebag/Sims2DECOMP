struct PlumbBob;

int PlumbBob_SomeFunc(int, PlumbBob*, int, int);

int PlumbBob_ResetMomentum(PlumbBob* self, int flag) {
    int r = PlumbBob_SomeFunc(flag, self, 0, 1);
    return r == 0;
}
