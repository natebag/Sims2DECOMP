int strround(char *s, int len)
{
    if (len > 0) {
        len = len - 1;
        if ((char)s[len] > '4') {
            do {
                s[len] = '0';
                len--;
                if (len <= 0) {
                    break;
                }
            } while (s[len] == '9');

            if (s[len] == '9') {
                return 0;
            }
            s[len] = s[len] + 1;
        }
    }
    return 1;
}
