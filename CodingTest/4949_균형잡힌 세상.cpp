/*
����� ������ �� �����־�� �Ѵ�. ��� ��, ���� ��� �׸��� ���� ��ȣ�� ������ ��ȣó�� ���̴�.

�������� �ӹ��� � ���ڿ��� �־����� ��, ��ȣ���� ������ �� ������ �ִ��� �Ǵ��ϴ� ���α׷��� ¥�� ���̴�.

���ڿ��� ���ԵǴ� ��ȣ�� �Ұ�ȣ("()") �� ���ȣ("[]")�� 2�����̰�, ���ڿ��� ������ �̷�� ������ �Ʒ��� ����.

��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.
�����̸� ���� ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ����� �Ǵ��غ���.
*/
#include <bits/stdc++.h>
using namespace std;

bool PrintNo()
{
	cout << "no" << "\n";
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		stack<char> S;
		string str;

		getline(cin, str);

		if (str == ".")
			break;

		bool b = false;
		for (char& chr : str)
		{
			if (chr == '(' || chr == '[')
				S.push(chr);

			else if (chr == ']')
			{
				if (S.empty())
				{
					b = PrintNo();
					break;
				}

				if (S.top() == '[')
					S.pop();
				else
				{
					b = PrintNo();
					break;
				}
			}
			else if (chr == ')')
			{
				if (S.empty())
				{
					b = PrintNo();
					break;
				}

				if (S.top() == '(')
					S.pop();
				else
				{
					b = PrintNo();
					break;
				}
			}
		}

		if(!b && S.size() == 0)
			cout << "yes" << "\n";
		else if(!b)
			cout << "no" << "\n";
	}

	return 0;
}