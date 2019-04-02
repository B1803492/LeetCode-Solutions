class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)   return s;
        int start = 0, max_len = 0;
        int i = 0;
        while (i < s.size()){
            int r_ptr = i;
            int l_ptr = i;
            //�ҳ��ظ��ִ�
            while (r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr+1])    r_ptr++;
            i = r_ptr+1;
            //���ظ��ִ�Ϊ���Ľ�����չ��������ڣ��������ھ���ѭ����ʼʱ��iֵ������չ
            while (r_ptr < s.size()-1 && l_ptr >0 && s[r_ptr+1] == s[l_ptr-1]){
                r_ptr++;
                l_ptr--;
            }
            int new_len = r_ptr - l_ptr + 1;
            if (new_len > max_len){
                start = l_ptr;
                max_len = new_len;
            }
        }
        return s.substr(start,max_len);
    }
};
