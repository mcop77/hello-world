/* Name: Marshall Copeland
Date: 09/15/20
Section: #10
Assignment: HW #2
Due Date: 09/25/20
About this project: For this homework, you will write a class called Date, in the files date.h and date.cpp, for creating and using objects that will store valid dates of the year.

All work below was performed by Marshall Copeland */

class Date
{
	public:
	Date(int defaultMonth = 1, int defaultDay = 1, int defaultYear = 2000);

		void Input();
		void Show() const;
		
		bool Set(int m, int d, int y);
		
		int GetMonth() const;
		int GetDay() const;
		int GetYear() const;
		
		bool SetFormat(char f);
		
		void Increment(int numDays = 1);
	
		int Compare(const Date& d) const;
		
	private:
		
		int Month;
		int Day;
		int Year;
		char Format;

	
	
};
