#include <iostream>
#include<fstream>

using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
int main()
{
   setlocale(LC_ALL, "rus");
#ifdef WRITE_TO_FILE
   char filname[_MAX_FNAME] = {};
   cout << "Введите имя файла: ";
   cin.getline(filname, _MAX_FNAME);
   if (strcmp(filname + strlen(filname) - 4, ".txt"))
	   strcat_s(filname, _MAX_FNAME, ".txt");

   ofstream fout;								 //1) создаем поток
   fout.open(filname,std::ios_base::app);        //2)Открываем поток //std::ios_base::app - дописываем в файл 
   fout << "Hello files!\n";					 //3) Пишем в поток
   fout.close();							     //4)Закрываем поток (ПОСЛЕ ИСПОЛЬЗОВАНИЯ ПОТОКА ОБЯЗАТЕЛЬНО ЗАКРЫВАЕМ ЕГО)
  
   char sz_command[_MAX_FNAME] = "notepad ";
   strcat_s(sz_command, _MAX_FNAME, filname);
   system(sz_command); //автоматически создает и открывает файл при компиляции // переписывает его содержимое каждый раз
#endif //WRITE_TO_FILE
#ifdef READ_FROM_FILE
   ifstream fin;
   fin.open("File.txt");
   if (fin.is_open())

   {
	   const int SIZE = 2048*100; //Размер буфера чтения
	   char sz_buffer[SIZE] = {};//Буфер чтения
	   while (!fin.eof()) // eof() - End of file
	   {
		 //  fin >> sz_buffer;
		   fin.getline(sz_buffer, SIZE);
		   cout << sz_buffer << endl;
	   }
	   fin.close();
   }
   else
   {
	   std::cerr << "Error: File not found" << endl;
	   //cout - console iut
	   //cerr - console error - консоль для вывода ошибок
   }
#endif
   char filname[_MAX_FNAME] = {};
   //cout << "Введите имя файла: ";
   //cin.getline(filname, _MAX_FNAME);
   if (strcmp(filname + strlen(filname) - 4, ".txt"))
	   strcat_s(filname, _MAX_FNAME, "201 ready.txt");
   
   ifstream fin;
   fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		   //const int SIZE = 2048 * 100; //Размер буфера чтения
		   const int IP_A = 16;//11 цифр 3 точки  и терм 0
		   char IP[IP_A] = {};//Буфер чтения
		   const int MAC_A = 18;//12 букв, цифр, 5 тире, терм 0
		   char MAC[MAC_A] = {};
		   while (!fin.eof()) // eof() - End of file
		   {
			   fin>>IP;
			   fin>>MAC;
			   cout << MAC <<" " << IP << endl;
		   }
		   fin.close();

	}
	else
	{
		   std::cerr << "Error: File not found" << endl;
		 
		   //cerr - console error - консоль для вывода ошибок
	}
	
}

