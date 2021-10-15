#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
class Koder{
	char m_klucz[16] = {};
	static int li;
	static int** tab[];
public:
	Koder(const char* i_klucz) { setKlucz(i_klucz); }

	void setKlucz(const char* i_klucz){
		if (i_klucz != nullptr)
			strncpy_s(m_klucz, i_klucz, 16);
		li++;
	}
	~Koder() {li--;}
	Koder(const Koder& org) {
		
		setKlucz(org.m_klucz);
		cout << "dzia³a konstruktor kopiujacy" << endl;
	}
	Koder(Koder&& org) noexcept {
		
		setKlucz(org.m_klucz);
		cout << "przenoszenie dzia³a" << endl;
	}
	void szyfruj(char* i_info, size_t i_liczZnak) const{
		if (i_info != nullptr && i_liczZnak > 0)
			for (size_t i = 0; i < i_liczZnak; i++)
				i_info[i] ^= m_klucz[i % 16];
	}
	void deszyfruj(char* i_info, size_t i_liczZnak) const{
		szyfruj(i_info, i_liczZnak);
	}
	static int getli() { return li; }
};
int Koder::li = 0;
bool test1() {
	Koder testowa("tekst");
	int i = Koder::getli();
	cout << i << endl;
	Koder testowa2 = testowa;
	cout << Koder::getli() << endl;
	return ((i + 1) == Koder::getli());
}
Koder fp() {
	Koder qwe("123");
	return qwe;
}
bool test2() {
	int i = Koder::getli();
	cout << i << endl;
	Koder asd = fp();
	cout << Koder::getli() << endl;
	return ((i + 1) == Koder::getli());
}
void main(void){
	Koder maszyna("1234567890");
	char wiadomosc[] = "Tajny Komunikat";
	int dlugosc = strlen(wiadomosc);
	cout << "Wiadomosc: " << wiadomosc << endl;
	maszyna.szyfruj(wiadomosc, dlugosc);
	cout << "Szyfrogram: " << wiadomosc << endl;
	maszyna.deszyfruj(wiadomosc, dlugosc);
	cout << "Wiadomosc: " << wiadomosc << endl;
	cout << test2();
}