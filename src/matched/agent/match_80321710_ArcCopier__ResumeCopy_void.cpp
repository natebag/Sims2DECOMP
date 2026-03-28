static int s_terminatingCopy;
class ArcCopier { public: void ResumeCopy(); };
void ArcCopier::ResumeCopy() { s_terminatingCopy = 0; }
