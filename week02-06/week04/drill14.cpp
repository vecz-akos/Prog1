#include <iostream>

class B1 {
public:
	virtual void vf() const {std::cout << "This is B1::vf()\n";}
	void f() {std::cout << "This is B1::f()\n";}
	virtual void pvf() = 0;
};

class B2 : public B1 {
public:
	void pvf() { std::cout << "This is B2::pvf()\n";}
};

class D1 : public B1 {
public:
	void vf() const {std::cout << "This is D1::vf()\n";}
	void pvf() { std::cout << "This is D1::pvf()\n";}
};

class D2 : public D1 {
public:
	void pvf() { std::cout << "This is D2::pvf()\n";}
};

class D21 : public B2 {
public:
	void pvf() { std::cout << testelek << std::endl;}
	std::string testelek = "testelek";
};

class D22 : public B2 {
public:
	void pvf() { std::cout << ten << std::endl;}
	int ten = 10;
};

class E : public B1 {
public:
	void vf() const { std::cout << "This is E::vf()\n";}
	void f() { std::cout << "This is E::f()\n";}
	void pvf() { std::cout << "This is E::pvf()\n";}
};

void new_line() { std::cout << std::endl;}

void b2_ref_arg(B2& b2) { b2.pvf();}

int main() {

	//B1 b1;	// error: because of pure virtual function
	//b1.vf();
	//b1.f();

	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	// reference

	new_line();
	B1& bref {d1};
	bref.vf();
	bref.f();
	bref.pvf();

	new_line();
	E e1;
	e1.vf();
	e1.f();
	e1.pvf();

	new_line();
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	new_line();
	D21 d21;
	D22 d22;
	b2_ref_arg(d21);
	b2_ref_arg(d22);

	return 0;
}