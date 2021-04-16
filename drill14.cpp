#include <iostream>

class B1
{
public:	
	virtual void vf() {std::cout << "B1::vf()" << std::endl;}
	void f() {std::cout << "B1::f()" << std::endl;}
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	virtual void vf() override{std::cout << "D1::vf()" << std::endl;}
	void f() { std::cout << "D1::f()" << std::endl;}
};

class D2 : public D1
{
public:
	virtual void pvf() override { std::cout << "D2::pvf()" << std::endl; }
};

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:
	std::string a = "string";
	virtual void vf() override { std::cout << a << std::endl; }
};

class D22 : public B2
{
public:
	int b = 23;
	virtual void vf() override { std::cout << b << std::endl; }
};

void f(B2& btwo_ref)
{
	btwo_ref.pvf();
}

int main()
{
	B1 bone;
	bone.vf();
	bone.f();

	D1 done;
	done.vf();
	done.vf();

	B1& bone_ref = done;
	bone_ref.vf();
	bone_ref.f();

	D2 dtwo;
	dtwo.f();
	dtwo.vf();
	dtwo.pvf();

	D21 dtwone;
	D22 dtwotwo;
	
	f(dtwone);
	f(dtwotwo);


}
