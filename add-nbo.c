#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t readbin(FILE* file) {
    uint32_t num = 0;
    fread(&num, sizeof(uint32_t), 1, file);
    return num;
}

void resultprint(uint32_t num1, uint32_t num2) {
    uint32_t sum = num1 + num2;
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
}

int main(int argc, char* argv[]) {
    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("I cant find file :/\n");
        return 0;
    }

    uint32_t num1 = readbin(file1);
    uint32_t num2 = readbin(file2);

    fclose(file1);
    fclose(file2);

    resultprint(ntohl(num1), ntohl(num2));

    return 0;
}

