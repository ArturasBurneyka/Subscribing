/*
*	How to build this application:
*	cd d:\Arthur\Subscribing
*	cl.exe /std:c++17 /W4 /EHsc Ep02.cpp /link /out:Subscribing2.exe
*/

#include <cstdio>
#include <functional>
#include <vector>

std::vector<std::function<void()>> vec;

auto f() -> void
{
	std::printf("auto f() -> void\n");
}

class X
{
public:
	X(){
		std::function<void()> bf = std::bind(&X::f, this);
		vec.push_back(bf);
	};
	void f() const { std::printf("X::f()\n"); };
};

auto main(int argc, char *argv[]) -> int
{	
	std::function<void()> bf = std::bind(f);
	vec.push_back(bf);
	vec[0]();
	
	X x;
	//std::function<void()> bxf = std::bind(&X::f, &x);
	//vec.push_back(bxf);
	vec[1]();
	
	return 0;
}