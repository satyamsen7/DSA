int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int totalRead = 0;
        char tempBuf[4];
        int readCount;

        while (totalRead < n) {
            readCount = read4(tempBuf);
            if (readCount == 0) break;

            int copyCount = std::min(readCount, n - totalRead);
            std::memcpy(buf + totalRead, tempBuf, copyCount);
            totalRead += copyCount;
        }

        return totalRead;
    }
};