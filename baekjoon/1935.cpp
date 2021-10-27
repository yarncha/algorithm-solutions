#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solution_1935() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_operands;	// 피연산자의 개수
	int operands[26];	// 각 영대문자에 해당하는 값을 넣어둘 배열
	cin >> num_of_operands;
	cin.ignore();

	string input_expression;	// 표현식
	getline(cin, input_expression);

	stack<double> stack_for_calculate;	// 계산한 값을 넣어둘 스택
	int operand;
	for (int j = 0; j < num_of_operands; j++)
	{
		// 배열에 각 피연산자에 대응되는 값을 저장함
		cin >> operand;
		operands[j] = operand;
	}
	for (int i = 0; i < input_expression.size(); i++)	//표현식을 하나씩 읽으며 식을 계산함
	{
		if (input_expression.at(i) >= 'A' && input_expression.at(i) <= 'Z') {
			// 문자가 나왔을 경우는 배열에서 값을 읽고, 스택에 push
			// 이 때 A는 65, Z는 90번임을 이용
			stack_for_calculate.push(operands[input_expression.at(i) - 'A']);
		}
		else {
			// 연산자가 나왔을 경우에는 스택에서 두개를 빼고 계산한 후 값을 집어넣음
			double front, end;

			if (input_expression.at(i) == '+') {
				end = stack_for_calculate.top();
				stack_for_calculate.pop();
				front = stack_for_calculate.top();
				stack_for_calculate.pop();
				stack_for_calculate.push(front + end);
			}
			else if (input_expression.at(i) == '-') {
				end = stack_for_calculate.top();
				stack_for_calculate.pop();
				front = stack_for_calculate.top();
				stack_for_calculate.pop();
				stack_for_calculate.push(front - end);
			}
			else if (input_expression.at(i) == '*') {
				end = stack_for_calculate.top();
				stack_for_calculate.pop();
				front = stack_for_calculate.top();
				stack_for_calculate.pop();
				stack_for_calculate.push(front * end);
			}
			else if (input_expression.at(i) == '/') {
				end = stack_for_calculate.top();
				stack_for_calculate.pop();
				front = stack_for_calculate.top();
				stack_for_calculate.pop();
				stack_for_calculate.push(front / end);
			}
		}
	}
	// 소수점 아래 2번째까지 출력하기 위한 코드
	cout << fixed;
	cout.precision(2);
	cout << stack_for_calculate.top() << "\n";
}

int main(void) {
	solution_1935();
	return 0;
}