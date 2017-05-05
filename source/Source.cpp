#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
const char filename[] = "c:\\file\\file.dat";

class Date;

//void write();
//void read();
//void welcome();
//int  wel_re();

class Date
{
private:
	int year;
	int month;
	int day;
	string item;
	int price;
public:
	Date()
	{
		year = 0;
		month = 0;
		day = 0;
		item = "";
		price = 0;
	}
	Date(int a, int b, int c, string d, int e)
	{
		year = a;
		month = b;
		day = c;
		item = d;
		price = e;
	}
	void setDate(int a, int b, int c, string d, int e)
	{
		year = a;
		month = b;
		day = c;
		item = d;
		price = e;
	}
	int getyear()
	{
		return year;
	}
	int getmonth()
	{
		return month;
	}
	int getday()
	{
		return day;
	}
	string getitem()
	{
		return item;
	}
	int getprice()
	{
		return price;
	}
	void setitem(string a)
	{
		item = a;
	}
	void setyear()
	{
		cout << "請輸入年分(輸入0結束):";
		cin >> year;
	}
	void setmonth()
	{
		cout << "請輸入月分(輸入0結束):";
		cin >> month;
	}
	void setday()
	{
		cout << "請輸入日期(輸入結束):";
		cin >> day;
	}
	void setitem()
	{
		cout << "請輸入項目名稱(輸入0結束):";
		cin >> item;
	}
	void setprice()
	{
		cout << "請輸入價錢(輸入0結束):";
		cin >> price;
	}
	friend istream & operator >> (istream& in, Date& obj);
	friend ostream & operator << (ostream& out, Date& obj);


	void welcome()
	{
		char option = 0;
		int repeat = 1;
		string str;

		cout << "歡迎使用本記帳程式\n";
		while (repeat)
		{
			cout << "1.記帳 2.查帳 : ";
			cin >> option;
			switch (option)
			{
			case '1':
				write();
				repeat = wel_re();
				break;
			case '2':
				cout << "\n請輸入關鍵字 : ";
				cin >> str;
				read(str);
				repeat = wel_re();
				break;
			default:
				cout << "\n無效輸入\n\n";
				break;
			}
		}
	}

	int  wel_re()
	{
		char repeat = '3';
		cout << "\n請問要再使用本程式嗎?\n";
		while (repeat == '3')
		{
			cout << "1.要 2.不要 : ";
			cin >> repeat;
			switch (repeat)
			{
			case '1':
				repeat = '1';
				break;
			case '2':
				repeat = '0';
				cout << "\n歡迎再次使用!\n\n";
				break;
			default:
				repeat = '3';
				cout << "無效輸入\n\n";
				break;
			}
		}
		if (repeat == '1')
			return 1;
		if (repeat == '0')
			return 0;
	}
	void write()
	{
		char question;
		Date form;
		ofstream filePtr;
		filePtr.open(filename, ios::app);
		if (!filePtr)
		{
			cout << "檔案開啟錯誤!\n";
			system("pause");
			exit(EXIT_FAILURE);
		}
		else
		{
			while (1)
			{
				form.setyear();
				if (form.getyear() == 0)
					break;
				form.setmonth();
				if (form.getmonth() == 0)
					break;
				form.setday();
				if (form.getday() == 0)
					break;
				form.setitem();
				if (form.getitem() == "0")
					break;
				form.setprice();
				if (form.getprice() == 0)
					break;
				cout << form;
				cout << "是否輸入正確(Y/N)? :";
				cin >> question;
				if (question == 'Y' || question == 'y')
					filePtr.write((char*)&form, sizeof(form));
				else
					cout << "判斷為輸入錯誤，請重新輸入。\n";
			}
		}
		filePtr.close();
	}
	void read(string search)
	{
		ifstream filePtr;
		string str;
		filePtr.open(filename, ios::binary | ios::in);
		if (!filePtr)
		{
			cout << "開啟輸入檔錯誤!\n";
			system("pause");
			exit(EXIT_FAILURE);

		}
		else
		{
			
			while (!filePtr.eof())
			{
				
				filePtr.read((char*)this, sizeof(*this));
				
				if (filePtr.eof())
					break;
				if (search == inttostr(year) || search == inttostr(month) || search == inttostr(day) || search == inttostr(price) || search == item)
				cout << *this;
				
			}
		}
		filePtr.close();
	}
	string inttostr(int data)
	{
		string temp_str;
		string str;
		int temp;
		int conv_time=0;
		temp = data;
		int minus = 0;
		if (temp < 0)
		{
			minus = 1;
			temp = abs(temp);
		}
		while (temp>0)
		{
			temp_str += temp % 10 + '0';
			temp = temp / 10;
			conv_time++;
		}
		
		if (minus == 0)
		{
			for (int i = 0; i < conv_time; i++)
			{
				str += temp_str.substr(conv_time - i - 1, 1);
			}
		}
		else
		{
			str += '-';
			for (int i = 0; i < conv_time; i++)
			{
				str += temp_str.substr(conv_time - i - 1, 1);
			}
		}
		return str;
	}
};
istream & operator >> (istream& in, Date& obj)
{
	cout << "請輸入日期: ";
	in >> obj.year >> obj.month >> obj.day;
	return in;
}
ostream & operator << (ostream& out, Date& obj)
{
	out << obj.year << "/" << obj.month << "/" << obj.day << "\t" << obj.item << "\t" << obj.price << "\n";
	return out;

}




int main()
{
	Date a;
	a.welcome();
	
	

	system("pause");
	return 0;
}

