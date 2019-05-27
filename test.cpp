#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

vector<int> two_D_matrix(int n, int k)
{
    vector<vector<int>> vec2D(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i<j)
                vec2D[i][j] = 1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << vec2D[i][j] << " ";
        cout << endl;
    }
    return vec2D[k];
}

int main()
{
    vector<int> vec = two_D_matrix(6,4);
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] << endl;
    return 0;
}








































/*
//Sorting Parallel vectors
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;


class Grade
{
public:
    Grade(int _user_id, int _grade)
    {
        user_id = _user_id;
        grade = _grade;
    };
    int get_user_id() {return user_id;};
    int get_grade() {return grade;};
private:
    int user_id;
    int grade;
};

class School
{
public:
    School(int _user_id, int _grade)
    {
        school_grades.push_back(Grade(_user_id, _grade));
        grades.push_back(_grade);
        user_ids.push_back(_user_id);
    };
    void add_info(int _user_id, int _grade)
    {
        school_grades.push_back(Grade(_user_id, _grade));
        grades.push_back(_grade);
        user_ids.push_back(_user_id);
    }
    vector<int> get_grades(){return grades;};
    vector<int> get_user_ids(){return user_ids;};
    vector<int> sort_films_rate(vector<int> sorted_films_id, vector<int> sorted_films_rate)
    {
        vector<int> sorted;
        int i, j, min, temp;
        for (i = 0; i < sorted_films_id.size()-1; i++) 
        {
            min = i;
            for (j = i + 1; j < sorted_films_id.size(); j++)
                if(sorted_films_rate[j] < sorted_films_rate[min])
                    min = j;
            temp = sorted_films_rate[i];
            sorted_films_rate[i] = sorted_films_rate[min];
            sorted_films_rate[min] = temp;
            temp = sorted_films_id[i];
            sorted_films_id[i] = sorted_films_id[min];
            sorted_films_id[min] = temp;
        }
        for(int i=sorted_films_id.size()-1; i > -1; i--)
        {
            sorted.push_back(sorted_films_id[i]);
        }
        return sorted;
    }

private:
    vector<Grade> school_grades;
    vector<int> grades;
    vector<int> user_ids;
};


int main()
{
    School S(1,18);
    S.add_info(2,10);
    S.add_info(3,19);
    S.add_info(4,15);
    S.add_info(5,13);
    vector<int> result = S.sort_films_rate(S.get_user_ids(), S.get_grades());
    for(int i=0; i<result.size(); i++)
        cout << result[i] << endl;
    return 0;
}*/