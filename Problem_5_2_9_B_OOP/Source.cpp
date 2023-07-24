#include <iostream>
#include <iomanip>

//
// In this task, you need to implement the [] operator for the 
// String class that you already know. However, this time the 
// operator must implement non-standard behavior: the operator 
// must be implemented in such a way that str[i][j] can be 
// written for the str object of the String class and this 
// expression returns a substring starting at position i 
// (counting from 0) and ending at position j (not including).
//


struct string
{
	string(const char* str_main = "")
	{
		this->size = strlen(str_main);
		char* new_str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_str[i] = str_main[i];
		}
		new_str[size] = '\0';
		this->str = new_str;
	}
	string(size_t n, char c)
	{
		this->size = n;
		char* new_str = new char[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			new_str[i] = c;
		}
		new_str[this->size] = '\0';
		this->str = new_str;
	}
	~string()
	{
		delete[] this->str;
	}
	string& operator=(const string& other)
	{
		if (this != &other)
		{
			delete[] str;
			this->size = other.size;
			this->str = new char[other.size + 1];
			for (int i = 0; i < other.size; i++)
			{
				this->str[i] = other.str[i];
			}
			this->str[other.size] = '\0';
		}
		return *this;
	}
	string(const string& other)
	{
		this->size = other.size;
		this->str = new char[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->str[i] = other.str[i];
		}

	}
	void append(const string& stroka)
	{
		size_t size_of_line2 = stroka.size;
		char* word = new char[this->size + stroka.size + 1];
		for (int i = 0; i < this->size; i++)
		{
			word[i] = this->str[i];
		}
		for (int i = this->size, k = 0; i < this->size + stroka.size; i++, k++)
		{
			word[i] = stroka.str[k];
		}
		word[this->size + stroka.size] = '\0';
		delete[] str;
		this->str = word;
		this->size = this->size + stroka.size;
		std::cout << this->str;
	}
	struct string_begin {
	private:
		const string& object;
		size_t begin;
		char* substr;
	public:
		string_begin(const string& str, size_t begin) : object(str), begin(begin), substr(nullptr){}
		
		const char* operator[](size_t end) {
			if (substr != nullptr) delete[] substr;
			if (end == begin || begin > end || begin >= object.size || end > object.size) {
				substr = new char[1];
				*substr = '\0';
				return substr;
			}
			substr = new char[end - begin + 2];
			int c = 0;
			for (int i = begin; i < end; i++) {
				*(substr + c) = *(object.str + i);
				c++;
			}
			if (end != begin) *(substr + end - begin) = '\0';
			return substr;
		}
		~string_begin() {
			delete[] substr;
		}
	};

	string_begin operator[](int begin) const{
		return string_begin(*this, begin);
	}

private:
	size_t size;
	char* str;
};



//template <typename T> class Matrix {
//private:
//    int n, m;
//    T** data;
//public:
//    Matrix(int n = 2, int m = 2) {
//        if (n < 2) n = 2;
//        if (m < 2) m = 2;
//        this->n = n;
//        this->m = m;
//        data = new T * [n];
//        for (int i = 0; i < n; i++) {
//            data[i] = new T[m];
//            for (int j = 0; j < m; j++) data[i][j] = (T)0;
//        }
//    }
//
//    class MatrixRow {
//    private:
//        Matrix& matr;
//        size_t _row;
//    public:
//        MatrixRow(Matrix& m, size_t row) : matr(m), _row(row) {}
//        MatrixRow(T* _array) : _row(_array) {}
//        T& operator [] (size_t col) {
//            return matr.data[_row][col];
//        }
//    };
//
//    MatrixRow operator [] (size_t index) {
//        return MatrixRow(*this, index);
//    }
//
//    void show(int width = 4) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) std::cout << std::setw(width) << data[i][j];
//            std::cout << std::endl;
//        }
//    }
//};

int main()
{
    //Matrix <double> a(2, 2);
    //a[1][0] = 1;
    //a[0][0] = a[1][1] + 1;
    //a.show();
    //std::cin.get();
	std::cout << "Start of the programm" << std::endl;
	string b("hello");

	const char* m = b[0][4];

	std::cout << m << std::endl;
	return 0;
}