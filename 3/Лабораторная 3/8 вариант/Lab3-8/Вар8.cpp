#include <iostream>
void main()
{
	double s, x = 0.1, j=12, y=5e-6, t;
	s=0.4*x-1/j*tan(y);
	t = s - sin(s);
	std::cout << "s = " << s << "\nt = " << t << std::endl;
}
