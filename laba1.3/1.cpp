#include <iostream>
#include <cstdio>
using namespace std;
//�������� ���� ������ ����������� ������� ��������� ����� �� ����� cstring, �
//������������ � ���������.� ������� main �� �������� ������ ������������������
//��������� ������ ��� ����������� �������, ��� � ����������� ������.���� - �����
//������ ������������ ���������� cstdio.

//������� strncat.
//������ char* strncat(char* dest, const char* src, size_t maxlen).
//������� ����������� maxlen �������� ������ src � ������ dest.


	void UniteStr(char* dest, char* src, size_t n) {

		while (*dest !='\0')
		{
			*dest++;
		}
		for (size_t i = 0; i < n; i++) {

			*dest = *src;
			*dest++;
			*src++;
		}
		*dest++;
		*dest = '\0';
	}

   int main() {

	
	char s1[255] = "funcua pripisuvaetmaxlen";
	char s2[255] = "simvolov stroki src k stroke dest.";

	printf("Vvedite chislo simvilov : ");
	int n = 0;
	cin >> n;

	printf("%s\n%s\n",s1, s2);

	UniteStr(s1, s2,n);
	printf("rezultat moei funk: %s\n", s1);
	strncat_s(s1, s2,n);
	printf("rezultat standartnoy funk: %s\n", s1);
	}
 