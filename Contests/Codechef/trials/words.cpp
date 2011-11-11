/* CODE: WORDS1 */

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		int a[26], b[26];
		for(int i = 0 ; i < 26; ++i)
			a[i] = b[i] = 0;

		while(N--)
		{
			string s;
			cin >> s;
			a[s[0]-'a']++;
			int len = s.size();
			b[s[len-1]-'a']++;
		}

		
		int count1 = 0;
		int count2 = 0;
		bool flag = false;
		for(int i = 0 ; i < 26; ++i)
		{
//			cout << a[i][0] << "  " << a[i][1] << endl;
			int diff = a[i] - b[i];
			if(diff == 1)
				++count1;
			else if(diff == -1)
				++count2;
			else if(diff != 0)
			{
				printf("%s\n", "The door cannot be opened.");
				flag = true;
				break;
			}
		}
		
		if(flag) continue;

		if( (count1 == 1) && (count2 == 1))
			printf("%s\n", "Ordering is possible.");
		else 
			printf("%s\n", "The door cannot be opened.");
	}
}
