// Academy.cpp 
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int year, int month, int day
#define HUMAN_GIVE_PARAMETERS last_name, first_name, year, month, day

class Human
{
    std::string last_name;
    std::string first_name;
    tm birth_date; //tm - timepoint

public:
    const std::string& get_last_name()const
    {
        return last_name;
    }
    const std::string& get_first_name()const
    {
        return first_name;
    }
    tm get_birth_date()const
    {
        return birth_date;
    }
    unsigned int get_age() const
    {
        time_t t_today = time(NULL);// Получаем текущие дату/время в формате Timestamp
     //   cout << today << endl;
        tm* tm_today = localtime(&t_today);
        unsigned int age = tm_today->tm_year - birth_date.tm_year;
        if (tm_today->tm_mon < birth_date.tm_mon)age--;
        if (tm_today->tm_mon == birth_date.tm_mon && tm_today->tm_mday < birth_date.tm_mday)age--;
        return age;
    }
    void set_last_name(const std::string& last_name)
    {
        this->last_name = last_name;
    }
    void set_first_name(const std::string& first_name)
    {
        this->first_name = first_name;
    }
    void set_birth_date(int year, int month, int day)
    {
        birth_date.tm_year = year - 1900;
        birth_date.tm_mon = month - 1;
        birth_date.tm_mday = day;
    }
    
// CONSTRUCTORS:
    Human(HUMAN_TAKE_PARAMETERS)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_birth_date(year, month, day);
        cout << "HConstructor:\t" << this << endl;

    }
// DESTRUCTOR:
    virtual ~Human()
    {
        cout << "HDestructor:\t" << this << endl;
    }
 // METODS:

    virtual void info()const
    {
        cout << last_name << " " << first_name << " " << get_age() << endl;
    }
};

#define STUDENT_TAKE_PARAMETERS  const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS  speciality, group, rating, attendance
class Student :public Human
{
    std::string speciality;
    std::string group;
    double rating;
    double attendance;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
    const std::string& get_group()const
    {
        return group;
    }
    double get_rating()const
    {
        return rating;
    }
    double get_attendance()const
    {
        return attendance;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void set_group(const std::string& group)
    {
        this->group = group;
    }
    void set_rating(double rating)
    {
        this->rating = rating;
    }
    void set_attendance(double attendance)
    {
        this->attendance = attendance;
    }
    // CONSTRUCTORS:
    Student
    (
        HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS)
        :Human(HUMAN_GIVE_PARAMETERS)//Вызов конструктора базового класса
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);
        cout << "SConstructor:\t" << this << endl;
    }
    Student(const Human& human,
            const std::string& speciality, const std::string& group, double rating, double attendance
           ):Human(human)
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);
        cout << "SConstructor:\t" << this << endl;
    }

    // DESTRUCTOR:
    ~Student()
    {
        cout << "SDestructor:\t" << this << endl;
    }
    // METODS:
    void info()const
    {
        Human::info();
        cout << speciality << " " << group << " " << rating << " " << attendance << endl;
    }
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
class Teacher : public Human
{
    std::string speciality;
    unsigned int experience;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
    unsigned int get_experience()const
    {
        return experience;
    }
    void set_speciality(const std::string& speciality)
    {

        this->speciality = speciality;
    }
    void set_experience(unsigned int experience)
    {

        this->experience = experience;
    }
    // CONSTRUCTORS:
    Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
    {
        set_speciality(speciality);
        set_experience(experience);
        cout << "TConstructor:\t" << this << endl;
    }
    // DESTRUCTOR:
    ~Teacher()
    {
        cout << "TDestructor:\t" << this << endl;
    }
    void info()const
    {
        Human::info();
        cout << speciality << " " << experience << " " << " лет.\n";
    }

};


class Graduate : public Student
{
    std::string subject;
public:
    const string& get_subject()const
    {
        return subject;
    }
    void set_subject(const std::string& subject)
    {
        this->subject = subject;
    }
    // CONSTRUCTORS:
    Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS,  const std::string& subject)
        :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
    {
        set_subject(subject);
        cout << "GConstructor:\t" << this << endl;
    }
    // DESTRUCTOR:
    ~Graduate()
    {
        cout << "GDestructor:\t" << this << endl;
    }
    void info()const
    {
        Student::info();
        cout << subject << endl;
    }
};

//#define TIME_CHECK
//#define INHERITANCE_CHECK
int main()
{
    setlocale(LC_ALL, "rus");
    #ifdef TIME_CHECK

    time_t t_today = time(NULL);// Получаем текущие дату/время в формате Timestamp
    cout << t_today << endl;
    tm* tm_today = localtime(&t_today);
    cout << tm_today->tm_year+1900 << "\t";
    cout << tm_today->tm_mon+1 << "\t";
    cout << tm_today->tm_mday << "\n";
    cout << asctime(tm_today) << endl;
#endif
#ifdef INHERITANCE_CHECK
    Human human("Тупенко", "Василий", 1990, 04, 01);
    human.info();

   // Student student("Тупенко", "Василий", 1990, 04, 01, "IT", "start", 60, 30);
    Student student(human, "IT", "start", 60, 30);
    student.info();

    Teacher teacher("Einstein", "Albert", 1879, 03, 14, "Astronomy", 120);
    teacher.info();

    Graduate graduate("Abignale", "Frank", 1920, 01, 02, "Artist", "Criminal", 98, 11,"Forgry documents");
    graduate.info();
#endif
    Human* group[] =
    {
        new Student("Pinkman", "Jessie",1990,03,04,"Chemistry","WW_220",90,95),
        new Teacher("White", "Walter",1960,9,20,"Chemistry",25),
        new Graduate("Scharader","Hank",1970,06,07,"Crimrnalistic","WW_220",75,80,"How to catch Heizenberg"),
        new Student("Vercetty", "Tomas",1970,05,25,"Crimrnalistic","Vice",90,95),
        new Teacher("Diaz", "Ricardo",1960,03,03,"Wapons distribution",20)
    };

    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        group[i]->info();
        cout << "\n-------------------------------------\n";
    }

    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        delete group[i];
    }
}

