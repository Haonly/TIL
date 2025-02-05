#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i = 1; i <= s.length()/2; i++){
        int len = s.length();
        for(int j = 0; j < s.length(); j++){
            for(int count = 0, z = i; j+z < s.length(); z += i){
                if(s.substr(j, i) == s.substr(j+z, i))
                    count++;
                else{
                    len -= i*count;
                    if(count)
                        len+= to_string(count+1).length();
                    j+=z-1;
                    break;
                }
                if(j+z+i >= s.length()){
                    len -= i*count;
                    len += to_string(count+ 1).length();
                    j += z;
                }
            }
        }
        if(len < answer)
            answer = len;
    }
    return answer;
}