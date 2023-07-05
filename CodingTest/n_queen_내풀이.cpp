	#include <bits/stdc++.h>
	using namespace std;

	int N;
	int answer = 0;
	vector<vector<bool>> board;


	void ClearBoard()
	{
		board.clear();
		board.resize(N);
		for (auto& vec : board)
			vec.resize(N, false);
	}

	void check(int row, int col)
	{
		// 2. ���� üũ
		for (int i = 0; i < N; i++)
		{
			if (i == col)
				continue;
			if (board[row][i] == true)
				return;
		}
		// 3. �밢 üũ
		int y1;
		int y2;
		for (int i = 0; i < N; i++)
		{
			if (i == col)
				continue;
			y1 = row - abs(col - i);
			y2 = row + abs(col - i);
			if (y1 >= 0)
			{
				if (board[y1][i] == true) 
					return;
			}
			if (y2 < N)
			{
				if (board[y2][i] == true)
					return;
			}
		}

		// 4. �����ϴٸ�? Booard�� üũ
		board[row][col] = true;


		// 5. ���� col üũ �� ���� Ȥ�� ���
		if (col == N - 1)
		{
			answer++;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				check(i, col + 1);
				board[i][col + 1] = false;
			}
			
		}
	}

	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> N;

		ClearBoard();

		for (int i = 0; i < N; i++)
		{
			check(i, 0);
			board[i][0] = false;
		}

		cout << answer;

		return 0;
	}