#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solution_1918() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string input_expression;	// 입력받은 중위표기식
	getline(cin, input_expression);

	stack<char> operator_stack;	// 연산자를 저장할 스택
	for (int i = 0; i < input_expression.size(); i++)
	{
		// 표기식을 하나씩 읽는다
		if (input_expression.at(i) >= 'A' && input_expression.at(i) <= 'Z') {
			// 영문자일 경우 그대로 출력
			cout << input_expression.at(i);
		}
		else {
			// 괄호가 나왔을 경우는
			if (input_expression.at(i) == '(') {
				//여는 괄호는 스택에 넣어주고
				operator_stack.push('(');
			}
			else if (input_expression.at(i) == ')') {
				// 닫는 괄호는 여는 괄호를 찾을 때까지 스택에서 pop한다
				while (operator_stack.top() != '(') {
					cout << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.pop();
			}
			else {
				// 괄호가 아닌 연산자가 나왔을 경우는
				// 현재 기호와 스택에 있는 기호를 비교해, 현재 기호가 더 우선순위가 큰 기호일 때까지 스택에서 뺀다.
				while (operator_stack.size() != 0 && operator_stack.top() != '(')
				{
					if ((operator_stack.top() == '+' || operator_stack.top() == '-') && (input_expression.at(i) == '*' || input_expression.at(i) == '/')) {
						break;
					}
					else {
						cout << operator_stack.top();
						operator_stack.pop();
					}
				}
				operator_stack.push(input_expression.at(i));
			}
		}
	}
	while (operator_stack.size() != 0) {
		cout << operator_stack.top();
		operator_stack.pop();
	}
}

int main(void) {
	solution_1918();
	return 0;
}