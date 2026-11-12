#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J"); // Clear screen

    for (;;) {
        memset(b, 32, sizeof(b)); // fill with spaces
        memset(z, 0, sizeof(z));  // reset z-buffer

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = (int)(40 + 30 * D * (l * h * m - t * n));
                int y = (int)(12 + 15 * D * (l * h * n + t * m));
                int o = x + 80 * y;
                int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    // b[o] = "123456789asadhsjaldhaskldhaklshdklasd"[N > 0 ? N : 0];
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        printf("\x1b[H"); // Reset cursor to top left
        for (k = 0; k < 1760; k++) {
            putchar(k % 80 ? b[k] : 10);
        }

        A += 0.004;
        B += 0.008;
        usleep(3000); // 30ms pause
    }

    return 0;
}
