#include <iostream>


// Инкапсуляция, агрегация, композиция

// Формирование класса

class NameOfClass; // Объявление класса

class NameOfClass {
	// внутренности фигурных скобок - тело класса.
	//тут хранятся свойства и поведения объектов

//хранящиеся здесь элементы доступны всем клиентам класса.
//Наследникам класса и клиентам наследника.

public:
	// обычно в этой зоне оставляют только методы классса
	NameOfClass() {
		SetEven(2);
		even_ = 2;
	}

	//конструктор применил делигацию работы для передачи прав на создание и заполнение своего поля\
	конструктору поля
	NameOfClass(int newNum) : even_(newNum)
	{
		if (even_ % 2 == 1) {
			throw 1;
		}
	}
	// делигация на поля применяется для возможности работы с универсаьной инициализацией через {} и является единственным способом заполнить поля \
	которые являются ссылками и неинециализированными константами


	void SomeWork() {
		std::cout << "I'm alive!\n";
	}
	int GetEven() {
		return even_;
	}
	void SetEven(int newNum) {
		if (newNum % 2 == 0) {
			even_ = newNum;
		}
		else {
			throw 1;
		}
	}
// хранящиеся здесь элементы доступны только членам класса, дружественным классам и функциям и членам классов наследников
protected:


// хранящиеся здесь элементы доступны только членам класса, дружественным классам и функциям
private:
	int even_;

}; // - определение класса.(как работает)




int main() {
	setlocale(LC_ALL, "ru");

	NameOfClass obj; // создали экземпляр класса с именем obj
	obj.SomeWork();
	obj.SetEven(8);
	std::cout << obj.GetEven() << '\n';

	NameOfClass obj2{10};
	std::cout << obj2.GetEven() << '\n';
	obj2.SetEven(4);
	std::cout << obj2.GetEven() << '\n';

	return 0;
}

class Day {
public:
	Day() : units_(0){}
	Day(int days) : units_(days) {
		if (units_ < 0) {
			throw 1;
		}
	}

	int Days() {
		return units_;
	}

	void Days(const Day& obj) {
		this->units_ = obj.units_;
	}
	void AddDays(const Day& obj) {
		this->units_ += obj.units_;
	}
private:
	int units_;
};

class Month {
public:
	Month() : units_(0) {}
	Month(int monts) : units_(monts) {
		if (units_ < 0) {
			throw 1;
		}
	}
	Month(Day days) {
		units_ = days.Days() / 30;
	}
	int Months() {
		return units_;
	}
	void Months(const Month& obj) {
		units_ = obj.units_;
	}
	void AddMonths(const Month& obj) {
		units_ += obj.units_;
	}
private:
	int units_;
};

class Year {
public:
	Year() : units_(0) {}
	Year(int years) : units_(years) {
		if (units_ < 0) {
			throw 1;
		}
	}
	Year(Day days) {
		units_ = days.Days() / 365;
	}
	Year(Month months) {
		units_ = months.Months() / 12;
	}
	int Years() {
		return units_;
	}
	void Years(const Year& obj) {
		units_ = obj.units_;
	}
	void AddYears(const Year& obj) {
		units_ += obj.units_;
	}
private:
	int units_;
};

class Date {
public:
	// тут будут правила класса - даты

private:
	Day day_;
	Month month_;
	Year year_;
};// данный класс собирает внутри себя объекты других классов на правах композиции

//композиция - способ связи поле класса с его объектом при котором поле является неотъемлемой частью объекта без которого невозможна работа.
//- объект в который сложены композиционные поля  несет ответственнось за время жизни вложеных компонентов


// Агрегация - способ связи полей класса с его объектом при котором поле является легко заменяемой частью класса. отсутствие  агрегационного компонента не ведет к проблемам в жизненном цикле хранящего данное поле объекта\
при агрегации хранящий объект не несет ответственности за время жизни хранимого н аправах агрегации поля