#include <iostream>
#include <random>
#include <time.h>

using namespace std;

class Student{
    private:
        int id;
        float grade;
    public: 
        static int count;
        Student(){
            id = Student::count++;
            grade = (rand()*100.0)/RAND_MAX;
        }
        int get_id(){return id;}
        float get_grade(){return grade;}
        static int get_count(){return count;}

};

int Student::count = 1000000;

class ClassroomAdmin{
    public:
        static int count_above(Student** c, int N, float grade)
        {
            int ans = 0;
            for( int i=0;i<N;i++)
            {
                if (c[i]->get_grade() > grade){
                    ans++;
                }
            }
            return ans;    
        }


};

int main(){
    srand(time(NULL));
    int N = 3000;
    Student** classroom;
    classroom = new Student*[N];
    for( int i=0;i<N;i++)
    {
        classroom[i] = new Student;
    }

    float G = 50;
    int ans = ClassroomAdmin::count_above(classroom,N,50.0);
    cout << ans << " students scored above " << G << endl;

    return 0;
}