static int s_terminatingCopy;
class ArcCopier { public: void TerminateCopy(); };
void ArcCopier::TerminateCopy() { s_terminatingCopy = 1; }
