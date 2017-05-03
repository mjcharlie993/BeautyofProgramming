#include <assert.h>
#include <stdio.h>
class CPrefixSorting {
public:
	CPrefixSorting() {
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	}

	~CPrefixSorting()
	{
		if (m_CakeArray != nullptr)
			delete m_CakeArray;
		if (m_SwapArray != nullptr)
			delete m_SwapArray;
		if (m_ReverseCakeArray != nullptr)
			delete m_ReverseCakeArray;
		if (m_ReverseCakeArraySwap != nullptr)
			delete m_ReverseCakeArraySwap;
	}
	
	void Run(int* pCakeArray, int nCakeCnt) {
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0);
	}

	void Output() {
		for (int i = 0; i != m_nMaxSwap; i++)
			printf("%d", m_SwapArray[i]);
		printf("\n |Search Time| : %d\n", m_nSearch);
		printf("Total Swap times = %d\n", m_nMaxSwap);
	}

private:
	void Init(int* pCakeArray, int nCakeCnt) {
		assert(pCakeArray != nullptr);
		assert(nCakeCnt > 0);

		m_nCakeCnt = nCakeCnt;
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != nullptr);
		for (int i = 0; i != m_nCakeCnt; i++)
			m_CakeArray[i] = pCakeArray[i];

		m_nMaxSwap = UpperBound(m_nCakeCnt);

		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray != nullptr);

		m_ReverseCakeArray = new int[m_nCakeCnt];
		for (int i = 0; i != m_nCakeCnt; i++)
			m_ReverseCakeArray[i] = m_CakeArray[i];
		m_ReverseCakeArraySwap = new int[m_nMaxSwap];
	}

	int UpperBound(int nCakeCnt) {
		return nCakeCnt * 2;
	}

	int LowerBound(int* pCakeArray, int nCakeCnt) {
		int t, ret = 0;

		for (int i = 1; i < nCakeCnt; i++) {
			t = pCakeArray[i] - pCakeArray[i - 1];
			if ((t == 1) || (t == -1)) {

			}
			else {
				ret++;
			}
		}
		return ret;
	}

	void Search(int step) {
		int i, nEstimate;
		m_nSearch++;
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
		if (step + nEstimate > m_nMaxSwap)
			return;
		if (isSorted(m_ReverseCakeArray, m_nCakeCnt)) {
			if (step < m_nMaxSwap) {
				m_nMaxSwap = step;
				for (i = 0; i != m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
			return;
		}
		for (int i = 1; i != m_nCakeCnt; i++) {
			Reverse(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Reverse(0, i);
		}
	}

	bool isSorted(int* pCakeArray, int nCakeCnt) {
		for (int i = 1; i != nCakeCnt; i++) {
			if (pCakeArray[i - 1] > pCakeArray[i]) {
				return false;
			}
		}
		return true;
	}

	void Reverse(int nBegin, int nEnd) {
		assert(nEnd > nBegin);
		int i, j, t;
		for (i = nBegin, j = nEnd; i < j; i++, j--) {
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}

private:
	int* m_CakeArray;
	int m_nCakeCnt;
	int m_nMaxSwap;
	int* m_SwapArray;
	int* m_ReverseCakeArray;
	int* m_ReverseCakeArraySwap;
	int m_nSearch;
};

void main() {
	CPrefixSorting x;
	int a[10] = { 3,2,1,6,5,4,9,8,7,0 };
	int cnt = 10;
	x.Run(a, cnt);
	x.Output();
}