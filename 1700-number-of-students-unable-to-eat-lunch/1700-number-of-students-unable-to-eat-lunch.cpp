class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sand;
        queue<int> stud;
        int count=0;
        
        for(int i=students.size()-1;i>=0;i--)
        {
            stud.push(students[i]);
            sand.push(sandwiches[i]);
        }    
        
        while(!sand.empty() && count<stud.size())
        {
            if(sand.top()==stud.front())
            {
                count=0;
                sand.pop();
                stud.pop();
            }
            else
            {
                count++;
                stud.push(stud.front());
                stud.pop();
            }
            
        }
        
        return stud.size();
    }
};