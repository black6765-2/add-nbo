#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "add-nbo.h"

int main(int argc, char* argv[])

{
	// argv[1]�� ���� �迭�Դϴ�. 
	char str1[SIZE];
	// argv[2]�� ���� �迭�Դϴ�. 
	char str2[SIZE];
	
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	
	// echo -n -e ��ɾ�� ������ ���̳ʸ� ������ ���ϴ�. 
	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");
	
	// ���̳ʸ� ������ �о� str1, str2�� ���� �����մϴ�. 
	fread(str1, sizeof(char), SIZE, fp1);
	fread(str2, sizeof(char), SIZE, fp2);
	
	// 16������ ������ ���ؼ� ���ڿ��� 16���� ���ڷ� ��ȯ�ϱ� ����, 0~9 / a~f / A~F�� ����ϴ�. 
	clear_str(str1);
	clear_str(str2);
	
	// ���ڿ��� 16���� ���ڷ� �ٲ��ִ� �Լ� stoh�� �̿��Ͽ� hex1, hex2�� 16���� ���ڸ� �����մϴ�. 
	uint32_t hex1 = stoh(str1);
	uint32_t hex2 = stoh(str2);

	// ������ ������ �� 16������ �� ������ �����Ͽ� result ������ �����մϴ�. 
	uint32_t result = hex1 + hex2;
	
	// ��� ���� 10������ 16������ ����մϴ�. 
	printf("%d(%#x) + %d(%#x) = %d(%#x)\n", hex1, hex1, hex2, hex2, result, result);
	
	fclose(fp2);
	fclose(fp1);
	
	return 0;
}
