#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// �� ���� �־������� �޾ƿ��� �̸� for������ �ݺ�
	int num_of_commands;
	cin >> num_of_commands;
	cin.ignore();

	string input_string;
	while (num_of_commands != 0)
	{
		//�� �� �Է¹ޱ�
		getline(cin, input_string);
		input_string.push_back('\n');

		char current_char;	//���� ����
		int is_vaild = 0;	//�� ���� ��ȣ ���谡 �ùٸ���
		for (int j = 0; j < input_string.size(); j++)
		{
			// �Է¹��� ���� �� ���ھ� ������
			current_char = input_string[j];
			if (current_char == '(') {
				is_vaild++;
			}
			else if (current_char == ')') {
				is_vaild--;
			}
			else {
				break;
			}

			//������ �Ǿ��� ���� �̹� �ùٸ��� ���� ��ȣ����
			if (is_vaild < 0) {
				break;
			}
		}

		// �Է¹��� ��ȣ���� �ùٸ��� ��
		if (is_vaild == 0) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

		num_of_commands--;
	}

	return 0;
}